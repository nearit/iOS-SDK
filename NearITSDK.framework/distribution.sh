source ./distribution_config.private
echo "Distribution path: $DISTRIBUTION_PATH"

echo "Carthage build..."
carthage build --no-skip-current
echo "Carthage finished"

rm -rf $DISTRIBUTION_PATH/docs
rm -rf $DISTRIBUTION_PATH/samples
rm -rf $DISTRIBUTION_PATH/NearITSDK.framework
rm -rf $DISTRIBUTION_PATH/NearITSDKSwift.framework

echo "Copying frameworks..."
cp -avR Carthage/Build/iOS/NearITSDK.framework $DISTRIBUTION_PATH/NearITSDK.framework
# cp -avR Carthage/Build/iOS/NearITSDKSwift.framework $DISTRIBUTION_PATH/NearITSDKSwift.framework
mkdir $DISTRIBUTION_PATH/NearITSDKSwift/
cp -avR NearITSDKSwift/{NearITSDKSwift.h,NearManager.swift} $DISTRIBUTION_PATH/NearITSDKSwift/
echo "Copying frameworks finished"

echo "Copying docs directory..."
cp -avR docs $DISTRIBUTION_PATH
echo "Docs copy finished"
cp -avR samples $DISTRIBUTION_PATH

rm -rf Carthage
