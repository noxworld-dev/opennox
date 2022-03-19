# Code cleanup/refactoring guide

PRs that cleanup or refactor code should contain separate commits with roughly the following order: 
- [Renames](#renaming) of functions or variables.
- Changes of [variable types](#changes-of-the-variable-types) (one variable per commit).
- Changing the code of functions (one function per commit).

## Renaming

When renaming a procedure name, stick to the naming scheme:

```
<module>_<component>_<action>_<original_address>
```

Example: when renaming a procedure named `sub_112233`, it should be named as `nox_network_playerinfo_112233`, 
where `nox` is the module (other possible module names are `mix` and `unimod`), `network` is the component, 
`playerinfo` is the action, and `112233` is the original HEX address of the procedure in the original Nox binary.

In cases where there is not enough information to rename the procedure (eg the action is not clear, but the module and component are known), the action can be skipped, eg `nox_network_112233`.
Doing so helps understanding what kind of data the procedures operates on, and will aid with understanding the callers/callees.
The name can be modified further once the action is understood.

Also, make sure your IDE replaces *all* usages and not only ones under the current `#ifdef`s.

## Changes of the variable types

### Changing the function argument type

Prefer to change the argument types in two steps:

First, change the type of the argument, give it a new name, and immediately assign new name to an variable with an old type and an old name:

```c
void foo(int a1, int a2) {
	// ...
}

// ->

void foo(void* ptr, int a2) {
	int a1 = ptr;
	// ...
}
```

Then rewrite the function assuming a new type.

Doing it in two steps (and two commits) allows to keep the changes to the types (that cannot lead to bugs) separate from
a function body rewrite (that may lead to bugs and may need to be reverted later).

### Changing integer variables to pointers

Changing integer variables to pointers may lead to bugs if the variable is used in the pointer arithmetic.
When doing such refactorings, follow the next steps:

1. Change the type to `void*` and try to compile. If it does, then you can continue to 3, if not...
2. Fix all compilation errors in the pointer arithmetic to include an explicit type cast to `uintptr_t`: `p + 4*a` -> `(uintptr_t)p + 4*a`.
3. Change the type of the pointer to the correct one, e.g. `char*` without changing the accesses to it.
4. Start changing the accesses. Make multiple commits to make it easier to find bugs, in case you make a typo somewhere.

The step 2 may require to make hundrends of replacements, so there are a few tips how you can do it semi-automatically.

- Instead of looking for usages of the variables, start by looking for all string matches. This will help avoid `#ifdef` issues.
- Examine the usages, find patterns. For example, for arrays you may find assignments (`*(uint32_t*)(&p) = a;`), dereferences of different kinds (`*(uint32_t*)(p + 4*a)`), etc.
- Make an automated replacement of specific patterns. Make sure to include at least one token on the right and left to replace only that specific usage pattern. For example, in `*(uint32_t*)(p + 4*a)` you should look for `(p +` and replace it with `((uintptr_t)p +`, NOT a `p` to `(uintptr_t)p`.
