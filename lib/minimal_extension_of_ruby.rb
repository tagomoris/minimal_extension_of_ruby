begin
  require "minimal_extension_of_ruby/#{RUBY_VERSION[/\d+\.\d+/]}/minimal_extension_of_ruby"
rescue LoadError
  require "minimal_extension_of_ruby/minimal_extension_of_ruby"
end

class MinimalExtensionOfRuby
end
