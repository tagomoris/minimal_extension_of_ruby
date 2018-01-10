
require 'bundler'
Bundler::GemHelper.install_tasks

require 'fileutils'

require 'rspec/core'
require 'rspec/core/rake_task'
require 'yard'

require 'rake/extensiontask'

spec = eval File.read("minimal_extension_of_ruby.gemspec")
Rake::ExtensionTask.new('minimal_extension_of_ruby', spec) do |ext|
  ext.ext_dir = 'ext/minimal_extension_of_ruby'
  ext.lib_dir = File.join(*['lib', 'minimal_extension_of_ruby', ENV['FAT_DIR']].compact)
end

CLEAN.include('lib/minimal_extension_of_ruby/minimal_extension_of_ruby.*')
