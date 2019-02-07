//
//  NearButton.swift
//  NearSample
//
//  Created by francesco.leoni on 24/11/17.
//  Copyright © 2017 Near Srl. All rights reserved.
//

import UIKit
import Hex

class NearButton: UIButton {
    
    override func awakeFromNib() {
        backgroundColor = UIColor(hex:"#333333")
        layer.cornerRadius = 18
        contentEdgeInsets = UIEdgeInsets(top: 0, left: 10, bottom: 0, right: 10)
    }

}
