//
//  MonitoringViewController.swift
//  SampleApp-Swift
//
//  Created by Nir Lachman on 12/02/2018.
//  Copyright © 2018 LivePerson. All rights reserved.
//

import UIKit
import LPMessagingSDK

import Auth0

class MonitoringViewController: UIViewController {
    
    //MARK: - UI Properties
    @IBOutlet var accountTextField: UITextField!
    @IBOutlet var appInstallIdentifierTextField: UITextField!
    
    //MARK: - Properties
    private var pageId: String?
    private var campaignInfo: LPCampaignInfo?
    
    // Enter Your Consumer Identifier
    private let consumerID: String? = "auth0|5d91bbac326dfe0dd96246e8"
    private let issuer: String? = "https://rmaeda.au.auth0.com/"
    
    //MARK: - Lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Enter Your Account Number
        self.accountTextField.text = "87301551"
        
        // Enter Your App Install Identifier
        self.appInstallIdentifierTextField.text = "b1026930-2fa4-4516-a5b7-e0c8df3edf8d"
    }

    // MARK: - IBActions
    @IBAction func initSDKsClicked(_ sender: Any) {
        defer { self.view.endEditing(true) }
        
        guard let accountNumber = self.accountTextField.text, !accountNumber.isEmpty else {
            print("missing account number!")
            return
        }
        
        self.campaignInfo = LPCampaignInfo (campaignId: 1122915870, engagementId: 1122930970, contextId: nil)
        
        guard let appInstallID = self.appInstallIdentifierTextField.text, !appInstallID.isEmpty  else {
            print("missing app install Identifier")
            return
        }
        
        initLPSDKwith(accountNumber: accountNumber, appInstallIdentifier: appInstallID)
    }
    
    @IBAction func getEngagementClicked(_ sender: Any) {
        let entryPoints = ["ios"]
        /*
        let entryPoints = ["tel://972737004000",
                           "http://www.liveperson.com",
                           "sec://Sport",
                           "lang://Eng"]
         */
        
        let engagementAttributes = [
            ["type": "purchase", "total": 20.0],
            ["type": "lead",
             "lead": ["topic": "luxury car test drive 2015",
                      "value": 22.22,
                      "leadId": "xyz123"]]
        ]

        getEngagement(entryPoints: entryPoints, engagementAttributes: engagementAttributes)
    }
    
    @IBAction func sendSDEClicked(_ sender: Any) {
        let entryPoints = ["http://www.liveperson-test.com",
                           "sec://Food",
                           "lang://De"]
        
        let engagementAttributes = [
            ["type": "purchase",
             "total": 11.7,
             "orderId": "DRV1534XC"],
            ["type": "lead",
             "lead": ["topic": "luxury car test drive 2015",
                      "value": 22.22,
                      "leadId": "xyz123"]]
        ]

        sendSDEwith(entryPoints: entryPoints, engagementAttributes: engagementAttributes)
    }
    
    @IBAction func showConversationWithCampaignClicked(_ sender: Any) {
        defer { self.view.endEditing(true) }
        
        guard let accountNumber = self.accountTextField.text, !accountNumber.isEmpty  else {
            print("Can't show conversation without valid account number")
            return
        }
        

        guard let campaignInfo = self.campaignInfo  else {
            print("Can't show conversation without valid campaignInfo")
            return
        }
        
        // let redirectURI = "https://rmaeda.au.auth0.com/authorize"
        let redirectURI = "https://rmaeda.au.auth0.com/oauth/token"
        let conversationQuery = LPMessaging.instance.getConversationBrandQuery(accountNumber, campaignInfo: campaignInfo)
        let conversationViewParam = LPConversationViewParams(conversationQuery: conversationQuery, isViewOnly: false)
        
        Auth0
            .webAuth(clientId: "H1lgb5JC5pLuqTjNLY5U5P3duMiFul0I", domain: "rmaeda.au.auth0.com")
            .nonce("hoge")
            .audience("https://rmaeda.au.auth0.com/userinfo")
            .responseType([.idToken])
            .scope("openid profile")
            .start {
                switch $0 {
                case .failure(let error):
                    print ("Error: \(error)")
                case .success(let credentials):
                    print("Credentials: \(credentials)")
                    let authenticationParams = LPAuthenticationParams(authenticationCode: nil,
                                                                      jwt: credentials.idToken,
                                                                      redirectURI: redirectURI,
                                                                      certPinningPublicKeys: nil,
                                                                      authenticationType: .authenticated)

                    DispatchQueue.main.async {
                        LPMessaging.instance.showConversation(conversationViewParam, authenticationParams: authenticationParams)
                    }
                }
        }

        // showConversationWith(accountNumber: accountNumber, campaignInfo: campaignInfo)
    }
    
    @IBAction func logoutClicked(_ sender: Any) {
        logoutLPSDK()
    }
}

// MARK: - LPMessagingSDK Helpers
extension MonitoringViewController {
    /**
     This method initialize with brandID (account number) and LPMonitoringInitParams (For monitoring)
     
     for more information on `initialize` see:
         https://developers.liveperson.com/mobile-app-messaging-sdk-for-ios-sdk-apis-messaging-api.html#initialize
     */
    private func initLPSDKwith(accountNumber: String, appInstallIdentifier: String) {
        let monitoringInitParams = LPMonitoringInitParams(appInstallID: appInstallIdentifier)
        
        do {
            try LPMessaging.instance.initialize(accountNumber, monitoringInitParams: monitoringInitParams)
        } catch let error as NSError {
            print("initialize error: \(error)")
        }
    }
    
    /**
     This method gets an engagement using LPMonitoingAPI
     - NOTE: CampaignInfo will be saved in the response in order to start a conversation later (showConversation method from LPMessagingSDK)
     
     for more information on `showconversation` see:
        https://developers.liveperson.com/mobile-app-messaging-sdk-for-ios-sdk-apis-monitoring-api.html#getengagement
    */
    private func getEngagement(entryPoints: [String], engagementAttributes: [[String:Any]]) {
        //resetting pageId and campaignInfo
        self.pageId = nil
        // self.campaignInfo = nil
        self.campaignInfo = LPCampaignInfo (campaignId: 1122915870, engagementId: 1122930970, contextId: nil)

        let monitoringParams = LPMonitoringParams(entryPoints: entryPoints, engagementAttributes: engagementAttributes)
        let identity = LPMonitoringIdentity(consumerID: consumerID, issuer: nil)
        LPMessaging.instance.getEngagement(identities: [identity], monitoringParams: monitoringParams, completion: { [weak self] (getEngagementResponse) in
            print("received get engagement response with pageID: \(String(describing: getEngagementResponse.pageId)), campaignID: \(String(describing: getEngagementResponse.engagementDetails?.first?.campaignId)), engagementID: \(String(describing: getEngagementResponse.engagementDetails?.first?.engagementId))")
            // Save PageId for future reference
            self?.pageId = getEngagementResponse.pageId
            if let campaignID = getEngagementResponse.engagementDetails?.first?.campaignId,
                let engagementID = getEngagementResponse.engagementDetails?.first?.engagementId,
                let contextID = getEngagementResponse.engagementDetails?.first?.contextId,
                let sessionID = getEngagementResponse.sessionId,
                let visitorID = getEngagementResponse.visitorId {
                self?.campaignInfo = LPCampaignInfo(campaignId: campaignID, engagementId: engagementID, contextId: contextID, sessionId: sessionID, visitorId: visitorID)
            } else {
                print("no campaign info found!")
            }
        }) { (error) in
            print("get engagement error: \(error.userInfo.description)")
        }
    }
    
    /**
     This method sends a new SDE using LPMonitoringAPI
     - NOTE: PageID in the response will be saved for future request for SDE
     
     for more information on `showconversation` see:
        https://developers.liveperson.com/mobile-app-messaging-sdk-for-ios-sdk-apis-monitoring-api.html#sendsde
     */
    private func sendSDEwith(entryPoints: [String], engagementAttributes: [[String:Any]]) {
        let monitoringParams = LPMonitoringParams(entryPoints: entryPoints, engagementAttributes: engagementAttributes, pageId: self.pageId)
        let identity = LPMonitoringIdentity(consumerID: consumerID, issuer: nil)
        LPMessaging.instance.sendSDE(identities: [identity], monitoringParams: monitoringParams, completion: { [weak self] (sendSdeResponse) in
            print("received send sde response with pageID: \(String(describing: sendSdeResponse.pageId))")
            // Save PageId for future reference
            self?.pageId = sendSdeResponse.pageId
        }) { [weak self] (error) in
            self?.pageId = nil
            print("send sde error: \(error.userInfo.description)")
        }
    }
    
    /**
     This method starts a new messaging conversation with account number and CampaignInfo (which was obtain from getEngagement)
     
     for more information on `showconversation` see:
         https://developers.liveperson.com/mobile-app-messaging-sdk-for-ios-sdk-apis-messaging-api.html#showconversation
     */
    private func showConversationWith(accountNumber: String, campaignInfo: LPCampaignInfo) {
        let conversationQuery = LPMessaging.instance.getConversationBrandQuery(accountNumber, campaignInfo: campaignInfo)
        let conversationViewParam = LPConversationViewParams(conversationQuery: conversationQuery, isViewOnly: false)
        LPMessaging.instance.showConversation(conversationViewParam)
    }
    
    /**
     This method logouts from Monitoring and Messaging SDKs - all the data will be cleared
     
     for more information on `logout` see:
        https://developers.liveperson.com/mobile-app-messaging-sdk-for-ios-methods-logout.html
     */
    private func logoutLPSDK() {
        LPMessaging.instance.logout(unregisterType: .all, completion: {
            print("successfully logout from MessagingSDK")
        }) { (errors) in
            print("failed to logout from MessagingSDK - error: \(errors)")
        }
    }
}
