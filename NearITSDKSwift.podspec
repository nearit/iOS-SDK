Pod::Spec.new do |s|

s.name                  = 'NearITSDKSwift'
s.version               = '2.10.4'
s.summary               = 'nearit.com iOS SDK'
s.description           = 'nearit.com iOS SDK for Swift'

s.homepage              = 'https://github.com/nearit/iOS-SDK'
s.license               = 'MIT'

s.author                = {
'Francesco Leoni' => 'francesco@nearit.com',
'Stefano Cattaneo' => 'stefano@nearit.com'
}
s.source                = { :git => "https://github.com/nearit/iOS-SDK.git", :tag => s.version.to_s }

s.ios.deployment_target = '9.0'
s.requires_arc          = true
s.source_files          =  'NearITSDKSwift/*.{h,swift}'

s.dependency            'NearITSDK', '= 2.10.4'

end
