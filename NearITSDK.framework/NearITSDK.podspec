Pod::Spec.new do |s|

s.name                  = 'NearITSDK'
s.version               = '2.2.6'
s.summary               = 'nearit.com iOS SDK'
s.description           = 'nearit.com iOS SDK for Objective-C'

s.homepage              = 'https://github.com/nearit/Near-iOS-SDK'
s.license               = 'MIT'

s.author                = {
'Francesco Leoni' => 'francesco@nearit.com'
}
s.source                = { :git => "https://github.com/nearit/Near-iOS-SDK.git", :tag => s.version.to_s }

s.source_files          = 'NearITSDK', 'NearITSDK/**/*.{h,m}'
s.ios.deployment_target = '9.0'
s.requires_arc          = true
s.xcconfig              = { "OTHER_LDFLAGS" => "-lz" }

end
