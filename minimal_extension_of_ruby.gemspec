$LOAD_PATH.push File.expand_path("../lib", __FILE__)
require 'minimal_extension_of_ruby/version'

Gem::Specification.new do |s|
  s.name = "minimal_extension_of_ruby"
  s.version = MinimalExtensionOfRuby::VERSION
  s.summary = "Now Testing."
  s.description = %q{Testing.}
  s.authors = ["Satoshi Tagomori"]
  s.email = ["tagomoris@gmail.com"]
  s.license = "Apache 2.0"
  s.has_rdoc = false
  s.require_paths = ["lib"]
  s.files = `git ls-files`.split("\n")
  s.extensions = ["ext/minimal_extension_of_ruby/extconf.rb"]
  # s.test_files = `git ls-files -- {test,spec}/*`.split("\n")

  s.add_development_dependency 'bundler', ['~> 1.0']
  s.add_development_dependency 'rake'
end
