# mruby-button-m5stack   [![Build Status](https://travis-ci.org/mimaki/mruby-button-m5stakc.svg?branch=master)](https://travis-ci.org/mimaki/mruby-button-m5stack)
Button class for M5Stack

## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

  # ... (snip) ...

  conf.gem :git => 'https://github.com/mimaki/mruby-button-m5stack'
end
```

## Constants

### Button objects

- Button::A  
Left button
- Button::B  
Center button
- Button::C  
Right button

## Singleton methods

- Button.new(id) => Button

## Instance methods

- button.pressed? => true/false
- button.released? => true/false

## example
```ruby
puts Button::A.pressed?
until Button::B.pressed?
  # ...
end
```

## License
under the MIT License:
- see LICENSE file
