---
title: nestjs 使用class-validator自定义字段检测
date: 2019/12/28 10:00:00
categories: 技术
toc: True
tags: [js]
---

### 前言

nestjs 使用 class-validator 自定义字段检测

###

```js
@ValidatorConstraint({ async: true })
export class IsUserAlreadyExistConstraint
  implements ValidatorConstraintInterface {
  async validate(username: any, args: ValidationArguments) {
    const usersRepository = await getRepository(UserEntity);
    return !((await usersRepository.count({ username: username })) > 0);
  }
}

export function IsUserAlreadyExist(validationOptions?: ValidationOptions) {
  return function(object: Object, propertyName: string) {
    registerDecorator({
      target: object.constructor,
      propertyName: propertyName,
      options: validationOptions,
      constraints: [],
      validator: IsUserAlreadyExistConstraint
    });
  };
}
```

### 使用

```js
@IsUserAlreadyExist({ message: '用户名已经存在' })
username: string;
```
