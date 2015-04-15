//
//  DJClassDescription.h
//  DJToolKit
//
//  Created by Felix Lieb on 17.06.14.
//  Copyright (c) 2014 Felix Lieb. All rights reserved.
//

#import <Foundation/Foundation.h>





typedef NS_OPTIONS(NSUInteger, DJClassDescriptionOption) {
    DJClassDescriptionOption_EscapeNewlines = 1 << 0,    // Will display newlines as \n in the string (\\n)
    DJClassDescriptionOption_EscapeTabs     = 1 << 1     // Will display tabs as \t in the string (\\t)
};





/**
 Provides class-methods to help create description-strings for description-methods
 */
@interface DJClassDescription : NSObject

/**
 Returns a string-representation for NSNumbers with Boolean values
 
 When you use @YES- or @NO-literals, the resulting NSNumber-object will not return YES or NO as
 a stringValue. This method provides a representative string, especially for NSNumber-objects
 created with the @YES- or @NO-literals.
 
 @param number NSNumber, created with @YES or @NO
 @return String representation for the boolean NSNumber ("INVALID", if number is not @YES or @NO)
 */
+ (NSString *)descriptionForBooleanNumber:(NSNumber *)number;

/**
 Returns a simple string-representation of a given date (UTC)
 
 @param date Date-object to return a string-representation for
 @return String-representation of the given date (YYYY-MM-DD)
 */
+ (NSString *)descriptionForDate:(NSDate *)date;

/**
 Returns a simple string-representatino of a given object without using its description-method
 
 When you only want to get the class and pointer of an object, instead of its own description
 
 @param object The object to return a string-representation for
 @return String-representation of the given object with the format <class pointer>
 */
+ (NSString *)descriptionForObject:(id)object;

/**
 Returns a single-quoted string or an empty string, if string is nil
 
 When you put a nil-string into a string-format it will be formatted with '(null)'. This method
 will return an empty string for nil and two single-quotes for an empty string.
 
 @param string String to return a description-string for
 @return Single-quoted string containing the given string or an empty string, if the string was nil
 */
+ (NSString *)descriptionForString:(NSString *)string;

/**
 Returns a single-quoted string or an empty string, if string is nil, with a given maximum length
 
 When you put a nil-string into a string-format it will be formatted with '(null)'. This method
 will return an empty string for nil and two single-quotes for an empty string.
 
 @param string String to return a description-string for
 @param options Bitmask defining options for the string
 @param maxLength A maximum length of the returned string
 @return Single-quoted string containing the given string or an empty string, if the string was nil
 */
+ (NSString *)descriptionForString:(NSString *)string options:(DJClassDescriptionOption)options maxLength:(NSUInteger)maxLength;

/**
 Returns a string-representation of the given BOOL
 
 @param boolean The BOOL to return a string-representation for
 @return String-representation for the given BOOL (YES or NO)
 */
+ (NSString *)descriptionForBOOL:(BOOL)boolean;

/**
 Returns a string-representation of the given integer
 
 @param integer The integer to return a string-representation for
 @return String-representation for the given integer
 */
+ (NSString *)descriptionForInteger:(NSInteger)integer;

/**
 Returns a string-representation of the given unsigned integer
 
 @param unsignedInteger The unsigned integer to return a string-representation for
 @return String-representatin for the given unsigned integer
 */
+ (NSString *)descriptionForUnsignedInteger:(NSUInteger)unsignedInteger;

/**
 A lazily instantiated single date-formatter instance
 */
+ (NSDateFormatter *)simpleDateFormatter;

@end






























