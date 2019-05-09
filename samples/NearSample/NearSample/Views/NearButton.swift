//
//  NearButton.swift
//  NearSample
//
//  Created by francesco.leoni on 24/11/17.
//  Copyright © 2017 Near Srl. All rights reserved.
//

import UIKit

class NearButton: UIButton {
    
    override func awakeFromNib() {
        backgroundColor = UIColor.init(red: 51.0/255.0, green: 51.0/255.0, blue: 51.0/255.0, alpha: 1)
        layer.cornerRadius = 18
        contentEdgeInsets = UIEdgeInsets(top: 0, left: 10, bottom: 0, right: 10)
    }

}
