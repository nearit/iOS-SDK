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

    /*
    // Only override draw() if you perform custom drawing.
    // An empty implementation adversely affects performance during animation.
    override func draw(_ rect: CGRect) {
        // Drawing code
    }
    */
    
    override func awakeFromNib() {
        backgroundColor = UIColor(hex:"#333333")
        layer.cornerRadius = 18
        contentEdgeInsets = UIEdgeInsetsMake(0, 10, 0, 10)
    }

}
