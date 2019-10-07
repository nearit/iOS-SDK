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
    
    @IBOutlet weak var permissionBar: NITPermissionsView!
    @IBOutlet weak var notificationHistoryButton: UIButton!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        permissionBar.locationType = .always
        permissionBar.delegate = self
        
        NearManager.shared.notificationDelegate = self
        title = "Home"
        
        tabBarController?.tabBar.tintColor = UIColor(red: 159/255, green: 146/255, blue: 255/255, alpha: 1.0)
        
        let permissionVC = NITPermissionsViewController(
            type: .locationAndNotifications,
            locationType: .whenInUse,
            autoCloseDialog: .on)
        permissionVC.delegate = self
        permissionVC.show()
        
    }
    
    @IBAction func notificationHistory(_ sender: Any) {
        let notificationHistoryVC = NITNotificationHistoryViewController()
        notificationHistoryVC.show(navigationController: navigationController!, title: "My Inbox")
    }
    
    @IBAction func couponHistory(_ sender: Any) {
        let couponListVC = NITCouponListViewController()
        couponListVC.show(navigationController: navigationController!, title: "My Coupons")
    }
    
    
    @IBAction func triggerInAppEventTapped(_ sender: Any) {
        NearManager.shared.triggerInAppEvent("my_trigger")
    }
    
    @IBAction func maleProfilationTapped(_ sender: Any) {
        NearManager.shared.setUserData("gender", value: "male")
    }
    
    @IBAction func femaleProfilationTapped(_ sender: Any) {
        NearManager.shared.setUserData("gender", value: "female")
    }
    
    @IBAction func resetProfilationTapped(_ sender: Any) {
        NearManager.shared.setUserData("gender", value: nil)
    }
    
    @IBAction func documentationTapped(_ sender: Any) {
        if let url = URL(string: "https://docs.nearit.com/ios/") {
            UIApplication.shared.open(url)
        }
    }
}

extension HomeViewController: NearManagerNotificationDelegate {
    func manager(_ manager: NearManager, updatedHistoryWith items: [NITHistoryItem]?) {
        let count = items?.filter { $0.isNew }.count ?? 0
        let cta = "Notification History (" + String.init(count) + ")"
        self.notificationHistoryButton.setTitle(cta, for: .normal)
    }
}

extension HomeViewController: NITPermissionsViewControllerDelegate {
    func dialogClosed(locationGranted: Bool, notificationsGranted: Bool) {
        if (locationGranted && notificationsGranted) {
            NearManager.shared.start()
        }
    }
}

extension HomeViewController: NITPermissionsViewDelegate {
    func permissionView(_ permissionView: NITPermissionsView, didGrant granted: Bool) {
        if (granted) {
            NearManager.shared.start()
        }
    }
    
    func permissionView(_ permissionView: NITPermissionsView, colorDidChangeTo: UIColor) {
        
    }
}
