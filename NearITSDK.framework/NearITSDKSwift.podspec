Pod::Spec.new do |s|

s.name                  = 'NearITSDKSwift'
s.version               = '2.2.7'
s.summary               = 'nearit.com iOS SDK'
s.description           = 'nearit.com iOS SDK for Swift'

s.homepage              = 'https://github.com/nearit/Near-iOS-SDK'
s.license               = 'MIT'

s.author                = {
'Francesco Leoni' => 'francesco@nearit.com'
}
s.source                = { :git => "https://github.com/nearit/Near-iOS-SDK.git", :tag => s.version.to_s }

s.source_files          = 'NearITSDKSwift', 'NearITSDKSwift/**/*.{swift}'
s.ios.deployment_target = '9.0'
s.requires_arc          = true

s.dependency            'NearITSDK', '= 2.2.7'

end
