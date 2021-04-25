#
# Be sure to run `pod lib lint MMBLEManager.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MMBLEManager'
  s.version          = '1.0.11'
  s.summary          = 'MMBLEManager and ImageLib'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://office.paperang.com:90/iOS_Group/MMSpec.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'GitHolmesZhao' => '269258864@qq.com' }
  s.source           = { :git => 'https://github.com/PaperangTeam/MMBLEManager.git', :tag => s.version.to_s }
  #子分支

  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  #s.source_files = 'MMBLEManager/Classes/**/*'
  #s.vendored_libraries = 'MMBLEManager/Classes/ImageLib/libImgAlgorithm/*.a'

  #s.exclude_files = 'MMBLEManager/Classes/Compress'

  # s.subspec 'ImageLib' do |img|
  #  img.source_files = 'MMBLEManager/Classes/ImageLib/*'
  #  img.vendored_libraries = 'MMBLEManager/Classes/ImageLib/libImgAlgorithm/*.a'

  # end

  # s.resource_bundles = {
  #   'MMBLEManager' => ['MMBLEManager/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'

  # 配置当前库的 bitcode
   s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
   s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'ENABLE_BITCODE' => 'NO' }
   
  s.source_files = 'MMBLEManager.framework/Headers/*'
  s.ios.vendored_frameworks = ['MMBLEManager.framework']
   
  # 配置宿主工程的 bitcode
  #s.user_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }

   #s.dependency 'YYCategories'
#   s.dependency 'HXLanguageManager'
#   s.dependency 'WYDatabase'
#   s.dependency 'MMNetworkManager'
   #s.dependency 'YYModel'
   #s.dependency 'OpenUDID'


end
