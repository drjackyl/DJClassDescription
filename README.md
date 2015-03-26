# DJClassDescription

Convenience-class (Objective-C) to create descriptive NSStrings for properties in -debugDescription

## What it is good for

I like to put meaningful -debugDescription-implementations into my code. Many of the existing descriptions simply output one line with some comma-separated values, that are hard to read and understand. Usually I use these descriptions, when I'm debugging in Xcode, halt at breakpoints and print the description to the console to better understand the situation. A meaningful and easy-to-read output is very useful, when doing this.

## Example

```Objective-C
@interface SomeClass : NSObject

@property (nonatomic, getter=isThisOrThat) BOOL thisOrThat;
@property (nonatomic, strong) NSNumber *optionalOnOrOff;
@property (nonatomic) NSUInteger numberOfThose;
@property (nonatomic) NSDate *releaseDate;
@property (nonatomic, weak) id delegate;

@end



@implementation SomeClass

- (NSString *)debugDescription {
    /*
     The format will look like this:
     
     <SomeClass 0x6000000539b0
                delegate: <SomeDelegateClass 0x600000054200>
              thisOrThat: NO
         optionalOnOrOff: @YES
           numberOfThose: 23
             releaseDate: 2015-03-26
     >
     */
    return [NSString stringWithFormat:@"<%@ %p\n\t       delegate: %@\n\t     thisOrThat: %@\n\toptionalOnOrOff: %@\n\t  numberOfThose: %@\n\t    releaseDate: %@\n>",
            self.class, self,
            [DJClassDescription descriptionForObject:self.delegate],
            [DJClassDescription descriptionForBOOL:self.thisOrThat],
            [DJClassDescription descriptionForBooleanNumber:self.optionalOnOrOff],
            [DJClassDescription descriptionForUnsignedInteger:self.numberOfThose],
            [DJClassDescription descriptionForDate:self.releaseDate]];
}

@end
```

## Description format

I created a common format for -debugDescriptions, that is useful to me. It looks like this:

```
<SomeClass 0x6000000539b0
           delegate: <SomeDelegateClass 0x600000054200>
         thisOrThat: NO
    optionalOnOrOff: @YES
      numberOfThose: 23
        releaseDate: 2015-03-26
>
```

The format looks like this:

```
<%@ %p
           delegate: %@
         thisOrThat: %@
    optionalOnOrOff: %@
      numberOfThose: %@
        releaseDate: %@
>
```

To encode and decode it easily (escape newlines and tabs) I use the RegReplace-package for Sublime Text.



























