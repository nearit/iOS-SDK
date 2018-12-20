//
//  HomeViewController.swift
//  NearSample
//
//  Created by francesco.leoni on 13/11/17.
//  Copyright © 2017 Near Srl. All rights reserved.
//

import UIKit
import NearUIBinding
import NearITSDKSwift

class HomeViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        title = "Home"
        
        tabBarController?.tabBar.tintColor = UIColor(red: 159/255, green: 146/255, blue: 255/255, alpha: 1.0)
        
        let permissionVC = NITPermissionsViewController(type: .locationAndNotifications, locationType: .always, autoStartRadar: .off, autoCloseDialog: .on)
        permissionVC.delegate = self
        permissionVC.show()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func notificationHistory(_ sender: Any) {
        let historyVC = NITNotificationHistoryViewController()
        historyVC.show()
    }
    
    @IBAction func couponHistory(_ sender: Any) {
        let vc = NITCouponListViewController()
        vc.show()
    }
    
    @IBAction func tapTryWhat(_ sender: UIButton) {
        let whatAction = UIAlertController(title: "Try \"What\"", message: "Choose the type of content you wish to try", preferredStyle: .actionSheet)
        whatAction.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: { (action) in
            
        }))
        
        whatAction.addAction(UIAlertAction(title: "Simple notification", style: .default, handler: { (action) in
            self.showSimpleNotification()
        }))
        
        whatAction.addAction(UIAlertAction(title: "Content", style: .default, handler: { (action) in
            self.showContent()
        }))
        
        whatAction.addAction(UIAlertAction(title: "Feedback", style: .default, handler: { (action) in
            self.showFeedback()
        }))
        
        whatAction.addAction(UIAlertAction(title: "Coupon", style: .default, handler: { (action) in
            self.showCoupon()
        }))
        
        present(whatAction, animated: true, completion: nil)
    }
    
    func showSimpleNotification() {
        guard let appDelegate = UIApplication.shared.delegate as? AppDelegate else {
            return
        }
      
        // do not manually create NearIT content in your app, only deal with instances delivered by the library
        // this is just to showcase UI components
        let simple = NITSimpleNotification()
        simple.message = "Lorem ipsum dolor sit amet"
        
        appDelegate.handleNearContent(simple)
    }
    
    func showContent() {
        guard let appDelegate = UIApplication.shared.delegate as? AppDelegate else {
            return
        }
      
        // do not manually create NearIT content in your app, only deal with instances delivered by the library
        // this is just to showcase UI components
        let content = NITContent()
        content.title = "Lorem ipsum"
        content.content = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."
        
        appDelegate.handleNearContent(content)
    }
    
    func showFeedback() {
        guard let appDelegate = UIApplication.shared.delegate as? AppDelegate else {
            return
        }
        // do not manually create NearIT content in your app, only deal with instances delivered by the library
        // this is just to showcase UI components
        let feedback = NITFeedback()
        feedback.question = "Lorem ipsum dolor sit amet?"
        
        appDelegate.handleNearContent(feedback)
    }
    
    func showCoupon() {
        guard let appDelegate = UIApplication.shared.delegate as? AppDelegate else {
            return
        }
      
        // do not manually create NearIT content in your app, only deal with instances delivered by the library
        // this is just to showcase UI components
        let coupon = NITCoupon()
        coupon.couponDescription = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."
        coupon.value = "10 $"
        coupon.expiresAt = "2020-06-05T08:32:00.000Z"
        coupon.redeemableFrom = "2017-06-01T08:32:00.000Z"
        let claim = NITClaim()
        claim.serialNumber = "0123456789"
        coupon.claims = [claim]
        coupon.icon = NITImage()
        coupon.icon.image = ["square_300": ["url": "https://avatars0.githubusercontent.com/u/18052069?s=200&v=4"]]
        
        appDelegate.handleNearContent(coupon)
    }
}

extension HomeViewController: NITPermissionsViewControllerDelegate {
    
    func dialogClosed(locationGranted: Bool, notificationsGranted: Bool) {
        if (locationGranted && notificationsGranted) {
            NearManager.shared.start()
        }
    }
}
