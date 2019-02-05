Pod::Spec.new do |s|

s.name                  = 'NearITSDK'
s.version               = '2.11-alpha'
s.summary               = 'nearit.com iOS SDK'
s.description           = 'nearit.com iOS SDK for Objective-C'

s.homepage              = 'https://github.com/nearit/iOS-SDK'
s.license               = 'MIT'

s.author                = {
'Francesco Leoni' => 'francesco@nearit.com',
'Cattaneo Stefano' => 'stefano@nearit.com',
'Boschini Federico' => 'federico@nearit.com'
}
s.source                = { :git => "https://github.com/nearit/iOS-SDK.git", :tag => s.version.to_s }

s.ios.deployment_target = '9.0'
s.requires_arc          = true
s.xcconfig              = { "OTHER_LDFLAGS" => "-lz" }
s.vendored_frameworks   = 'NearITSDK.framework'
s.source_files =  'NearITSDK.framework/Headers/*.h'

end
