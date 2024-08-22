# Semantic Versioning (SemVer) Guide

## Table of Contents
1. [Introduction](#introduction)
2. [Why Use Semantic Versioning?](#why-use-semantic-versioning)
3. [Versioning Format](#versioning-format)
4. [Version Components](#version-components)
   - [1. MAJOR Version](#1-major-version)
   - [2. MINOR Version](#2-minor-version)
   - [3. PATCH Version](#3-patch-version)
5. [Pre-Release Versions](#pre-release-versions)
6. [Build Metadata](#build-metadata)
7. [Examples](#examples)
   - [Basic Examples](#basic-examples)
   - [Pre-Release Examples](#pre-release-examples)
   - [Build Metadata Examples](#build-metadata-examples)
8. [How to Apply Semantic Versioning](#how-to-apply-semantic-versioning)
   - [Step-by-Step Guide](#step-by-step-guide)
9. [Best Practices](#best-practices)
10. [FAQs](#faqs)
11. [References](#references)

---

## Introduction

Semantic Versioning (SemVer) is a versioning scheme for software that uses a three-part version number: `MAJOR.MINOR.PATCH`. It provides a standardized way to communicate the nature of changes in your software, making it easier for developers and users to understand the impact of updates.

## Why Use Semantic Versioning?

Semantic Versioning helps developers and users to:
- Understand the implications of upgrading to a new version.
- Maintain backward compatibility when adding new features.
- Clearly signal when breaking changes are introduced.

Using SemVer, you can:
- Minimize integration risks for users.
- Provide predictable and meaningful version numbers.
- Simplify the dependency management process.

## Versioning Format

The format for Semantic Versioning is:

```
MAJOR.MINOR.PATCH
```

Where:
- `MAJOR`: Incompatible API changes
- `MINOR`: Backward-compatible functionality
- `PATCH`: Backward-compatible bug fixes

## Version Components

### 1. MAJOR Version

- **Definition:** The MAJOR version number is incremented when you make incompatible API changes.
- **Impact:** Upgrading to a new MAJOR version may break compatibility with previous versions. Users may need to make changes to their code to accommodate the new version.
- **Example:** 
  - `1.0.0` → `2.0.0` (A breaking change was introduced.)
  - `3.2.1` → `4.0.0` (Major overhaul or redesign, breaking backward compatibility.)

### 2. MINOR Version

- **Definition:** The MINOR version number is incremented when you add functionality in a backward-compatible manner.
- **Impact:** Upgrading to a new MINOR version should not break existing code. It usually means new features or improvements have been added.
- **Example:**
  - `1.0.0` → `1.1.0` (A new feature was added.)
  - `2.3.4` → `2.4.0` (Enhancements or new functionality.)

### 3. PATCH Version

- **Definition:** The PATCH version number is incremented when you make backward-compatible bug fixes.
- **Impact:** Upgrading to a new PATCH version should not introduce new features or break existing functionality. It should only fix bugs.
- **Example:**
  - `1.0.0` → `1.0.1` (A bug was fixed.)
  - `2.1.3` → `2.1.4` (Minor fixes or optimizations.)

## Pre-Release Versions

- **Format:** `MAJOR.MINOR.PATCH-PRERELEASE`
- **Usage:** Pre-release versions are denoted by appending a hyphen and a series of identifiers (e.g., `alpha`, `beta`, `rc`).
- **Example:**
  - `1.0.0-alpha`
  - `1.0.0-beta`
  - `2.1.0-rc.1`

### Explanation:
- **`alpha`**: An early version, not feature-complete and may be unstable.
- **`beta`**: Feature-complete but may contain known issues.
- **`rc` (Release Candidate):** A version likely to be stable, pending final testing.

## Build Metadata

- **Format:** `MAJOR.MINOR.PATCH+BUILD`
- **Usage:** Build metadata is denoted by appending a plus sign and a series of identifiers.
- **Example:**
  - `1.0.0+20130313144700`
  - `1.2.3+exp.sha.5114f85`

### Explanation:
Build metadata does not affect the version precedence, meaning `1.0.0+build1` is considered equal to `1.0.0`.

## Examples

### Basic Examples

- **Breaking Change (Major Version Increase):**
  - `1.4.2` → `2.0.0`: Removing or changing a public API in a way that is not backward-compatible.

- **New Feature (Minor Version Increase):**
  - `2.1.0` → `2.2.0`: Adding a new method to a public API.

- **Bug Fix (Patch Version Increase):**
  - `3.5.1` → `3.5.2`: Fixing a bug in an existing method.

### Pre-Release Examples

- **Alpha Version:**
  - `1.0.0-alpha.1`: The first alpha version of `1.0.0`.

- **Beta Version:**
  - `1.0.0-beta.2`: The second beta version of `1.0.0`.

- **Release Candidate:**
  - `1.0.0-rc.1`: The first release candidate for `1.0.0`.

### Build Metadata Examples

- **Including Date:**
  - `2.3.1+20240820`: Version `2.3.1` with build metadata indicating it was built on August 20, 2024.

- **Including Build Number:**
  - `3.4.0+build-256`: Version `3.4.0` with the 256th build.

## How to Apply Semantic Versioning

### Step-by-Step Guide

1. **Identify the Type of Change:**
   - Is it a breaking change, a new feature, or a bug fix?

2. **Determine the Version Increment:**
   - Breaking change → Increment MAJOR
   - New feature → Increment MINOR
   - Bug fix → Increment PATCH

3. **Label Pre-Releases Appropriately:**
   - Use labels like `alpha`, `beta`, or `rc` for versions that are not yet stable.

4. **Optionally Add Build Metadata:**
   - Use build metadata to provide additional context, such as a build number or date.

## Best Practices

- **Document Changes:** Maintain a changelog that clearly documents what has changed in each version.
- **Test Thoroughly:** Before releasing a new version, especially MAJOR releases, ensure that thorough testing has been conducted.
- **Communicate Clearly:** Use version numbers to communicate the nature of changes to your users.
- **Avoid Skipping Versions:** It’s best to avoid skipping version numbers (e.g., going from `1.0.0` directly to `2.0.0` without an intermediate `1.1.0`).

## FAQs

**Q1: What should I do if a bug is discovered after a MAJOR release?**  
- Increment the PATCH version (e.g., `1.0.0` → `1.0.1`).

**Q2: Can I skip the MINOR version and go straight to a MAJOR release?**  
- Yes, but it’s best practice to increment versions sequentially to maintain clarity.

**Q3: Should I include the `v` prefix in version numbers?**  
- This is optional. Some projects use `v1.0.0` while others simply use `1.0.0`.

## References

- [Semantic Versioning Specification](https://semver.org/)
- [Versioning Best Practices](https://semver.org/#spec-item-11)
- [Changelog Best Practices](https://keepachangelog.com/)
