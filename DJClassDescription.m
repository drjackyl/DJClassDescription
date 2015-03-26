//
//  DJClassDescription.m
//  DJToolKit
//
//  Created by Felix Lieb on 17.06.14.
//  Copyright (c) 2014 Felix Lieb. All rights reserved.
//

#import "DJClassDescription.h"





#pragma mark -
#pragma mark Implementation
@implementation DJClassDescription

#pragma mark Class Methods
+ (NSString *)descriptionForBooleanNumber:(NSNumber *)number {
    if (number) {
        if ([number isEqualTo:@YES]) {
            return @"@YES";
        } else if ([number isEqualTo:@NO]) {
            return @"@NO";
        } else {
            return @"INVALID";
        }
    } else {
        return @"";
    }
}


+ (NSString *)descriptionForDate:(NSDate *)date {
    if (date) {
        return [[DJClassDescription simpleDateFormatter] stringFromDate:date];
    } else {
        return @"";
    }
}


+ (NSString *)descriptionForObject:(id)object {
    if (object) {
        if ([object isKindOfClass:[NSObject class]]) {
            return [NSString stringWithFormat:@"<%@ %p>", [(NSObject *)object class], object];
        } else {
            return [NSString stringWithFormat:@"<Unknown %p>", object];
        }
    } else {
        return @"";
    }
}


+ (NSString *)descriptionForString:(NSString *)string {
    if (string) {
        return [NSString stringWithFormat:@"'%@'", string];
    } else {
        return @"";
    }
}


+ (NSString *)descriptionForBOOL:(BOOL)boolean {
    return boolean ? @"YES" : @"NO";
}


+ (NSString *)descriptionForInteger:(NSInteger)integer {
    return [NSString stringWithFormat:@"%ld", (long)integer];
}


+ (NSString *)descriptionForUnsignedInteger:(NSUInteger)unsignedInteger {
    return [NSString stringWithFormat:@"%lu", (unsigned long)unsignedInteger];
}


+ (NSDateFormatter *)simpleDateFormatter {
    static NSDateFormatter *dateFormatter = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:@"yyyy-MM-dd"];
    });
    return dateFormatter;
}

@end






























