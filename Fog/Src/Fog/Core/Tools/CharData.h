// [Fog-Core]
//
// [License]
// MIT, See COPYING file in package

// [Guard]
#ifndef _FOG_CORE_TOOLS_CHARDATA_H
#define _FOG_CORE_TOOLS_CHARDATA_H

// [Dependencies]
#include <Fog/Core/Global/Global.h>

namespace Fog {

// ============================================================================
// [Define]
// ============================================================================

#define FOG_ISO15924_NAME(_A_, _B_, _C_, _D_) \
  ( ((uint32_t)(_A_) << 24) | \
    ((uint32_t)(_B_) << 16) | \
    ((uint32_t)(_C_) <<  8) | \
    ((uint32_t)(_D_)      ) )

// ============================================================================
// [Fog::CharInfo]
// ============================================================================

#include <Fog/Core/C++/PackByte.h>
//! @brief Extra property of single unicode character, see
//! @ref CharProperty::extraLink member.
struct FOG_NO_EXPORT CharInfo
{
  // --------------------------------------------------------------------------
  // [Accessors]
  // --------------------------------------------------------------------------

  // NOTE: Accessors are not sorted according to the members list.

  FOG_INLINE uint32_t getUnicodeVersion() const { return _unicodeVersion; }
  FOG_INLINE uint32_t getCombiningClass() const { return _combiningClass; }
  FOG_INLINE uint32_t getScript() const { return _script; }

  FOG_INLINE uint32_t getGraphemeBreak() const { return _graphemeBreak; }
  FOG_INLINE uint32_t getWordBreak() const { return _wordBreak; }
  FOG_INLINE uint32_t getSentenceBreak() const { return _sentenceBreak; }
  FOG_INLINE uint32_t getLineBreak() const { return _lineBreak; }

  FOG_INLINE uint32_t getBidi() const { return _bidi; }
  FOG_INLINE uint32_t getJoining() const { return _joining; }
  FOG_INLINE uint32_t getEastAsianWidth() const { return _eaw; }

  FOG_INLINE uint32_t getCompositionExclusion() const { return _compositionExclusion; }
  FOG_INLINE uint32_t getCompositionId() const { return _compositionId; }

  FOG_INLINE uint32_t quickCheckNFD() const { return _nfdQC; }
  FOG_INLINE uint32_t quickCheckNFC() const { return _nfcQC; }
  FOG_INLINE uint32_t quickCheckNFKD() const { return _nfkdQC; }
  FOG_INLINE uint32_t quickCheckNFKC() const { return _nfkcQC; }

  // --------------------------------------------------------------------------
  // [Members]
  // --------------------------------------------------------------------------

  // ${CHAR_INFO_CLASS:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  // First 32-bit packed int.
  uint32_t _combiningClass : 8;
  uint32_t _script : 8;
  uint32_t _unicodeVersion : 4;
  uint32_t _graphemeBreak : 4;
  uint32_t _wordBreak : 4;
  uint32_t _sentenceBreak : 4;

  // Second 32-bit packed int.
  uint32_t _lineBreak : 6;
  uint32_t _bidi : 5;
  uint32_t _joining : 3;
  uint32_t _eaw : 3;
  uint32_t _compositionExclusion : 1;
  uint32_t _nfdQC : 1;
  uint32_t _nfcQC : 2;
  uint32_t _nfkdQC : 1;
  uint32_t _nfkcQC : 2;
  uint32_t _compositionId : 8;

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_INFO_CLASS:END}
};
#include <Fog/Core/C++/PackRestore.h>

// ============================================================================
// [Fog::CharSpecial]
// ============================================================================

#include <Fog/Core/C++/PackByte.h>
//! @brief Property of special character.
struct FOG_NO_EXPORT CharSpecial
{
  // --------------------------------------------------------------------------
  // [Accessors]
  // --------------------------------------------------------------------------

  // NOTE: Accessors are not sorted according to the members list.

  // --------------------------------------------------------------------------
  // [Members]
  // --------------------------------------------------------------------------

  // ${CHAR_SPECIAL_CLASS:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  int32_t _upperCaseDiff : 22;
  int32_t _unused0 : 10;

  int32_t _lowerCaseDiff : 22;
  int32_t _unused1 : 10;

  int32_t _titleCaseDiff : 22;
  int32_t _unused2 : 10;

  int32_t _mirrorDiff : 22;
  int32_t _digitValue : 10;

  uint32_t _simpleCaseFolding;
  uint32_t _specialCaseFolding;
  uint32_t _fullCaseFolding[3];

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_SPECIAL_CLASS:END}
};
#include <Fog/Core/C++/PackRestore.h>

// ============================================================================
// [Fog::CharProperty]
// ============================================================================

#include <Fog/Core/C++/PackByte.h>
//! @brief Property of single unicode character.
struct FOG_NO_EXPORT CharProperty
{
  // --------------------------------------------------------------------------
  // [Accessors]
  // --------------------------------------------------------------------------

  // NOTE: Accessors are not sorted according to the members list.

  FOG_INLINE const CharInfo& getInfo() const;
  FOG_INLINE uint32_t getInfoIndex() const { return ((uint32_t)_infoAndMapping) & 0x00000FFF; }

  FOG_INLINE bool isSpecial() const { return getMappingType() == CHAR_MAPPING_SPECIAL; }
  FOG_INLINE const CharSpecial& getSpecial() const;

  FOG_INLINE uint32_t getMappingType() const { return ((uint32_t)_infoAndMapping >> 12) & 0x00000007; }
  FOG_INLINE int32_t getMappingData() const { return _infoAndMapping >> 15; }

  FOG_INLINE uint32_t getCategory() const { return _category; }
  FOG_INLINE bool isSpace() const { return _space; }

  FOG_INLINE uint32_t getUnicodeVersion() const { return getInfo().getUnicodeVersion(); }
  FOG_INLINE uint32_t getCombiningClass() const { return getInfo().getCombiningClass(); }
  FOG_INLINE uint32_t getScript() const { return getInfo().getScript(); }

  FOG_INLINE uint32_t getGraphemeBreak() const { return getInfo().getGraphemeBreak(); }
  FOG_INLINE uint32_t getWordBreak() const { return getInfo().getWordBreak(); }
  FOG_INLINE uint32_t getSentenceBreak() const { return getInfo().getSentenceBreak(); }
  FOG_INLINE uint32_t getLineBreak() const { return getInfo().getLineBreak(); }

  FOG_INLINE uint32_t getBidi() const { return getInfo().getBidi(); }
  FOG_INLINE uint32_t getJoining() const { return getInfo().getJoining(); }
  FOG_INLINE uint32_t getEastAsianWidth() const { return getInfo().getEastAsianWidth(); }

  FOG_INLINE uint32_t getCompositionExclusion() const { return getInfo().getCompositionExclusion(); }
  FOG_INLINE uint32_t getCompositionId() const { return getInfo().getCompositionId(); }
  FOG_INLINE uint32_t quickCheckNFD() const { return getInfo().quickCheckNFD(); }
  FOG_INLINE uint32_t quickCheckNFC() const { return getInfo().quickCheckNFC(); }
  FOG_INLINE uint32_t quickCheckNFKD() const { return getInfo().quickCheckNFKD(); }
  FOG_INLINE uint32_t quickCheckNFKC() const { return getInfo().quickCheckNFKC(); }

  FOG_INLINE bool hasComposition() const { return _hasComposition != 0; }
  FOG_INLINE bool hasDecomposition() const { return _decompositionIndex != 0 ; }
  FOG_INLINE uint32_t getDecompositionType() const { return _decompositionType; }

  FOG_INLINE const uint16_t* getDecompositionData() const;
  FOG_INLINE uint32_t getDecompositionIndex() const { return _decompositionIndex; }

  // --------------------------------------------------------------------------
  // [Members]
  // --------------------------------------------------------------------------

  // ${CHAR_PROPERTY_CLASS:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  // First 32-bit packed int.
  // - uint32_t _infoIndex : 12;
  // - uint32_t _mappingType : 3;
  // - int32_t _mappingData : 17;
  // Needed to pack to a signle integer, because of different types used.
  int32_t _infoAndMapping;

  // Second 32-bit packed int.
  uint32_t _category : 5;
  uint32_t _space : 1;
  uint32_t _hasComposition : 1;
  uint32_t _decompositionType : 5;
  uint32_t _decompositionIndex : 15;
  uint32_t _unused : 5;

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_PROPERTY_CLASS:END}
};
#include <Fog/Core/C++/PackRestore.h>

// ============================================================================
// [Fog::CharComposition]
// ============================================================================

struct FOG_NO_EXPORT CharComposition
{
  // --------------------------------------------------------------------------
  // [Accessors]
  // --------------------------------------------------------------------------

  FOG_INLINE uint32_t getA() const { return static_cast<uint32_t>(_a); }
  FOG_INLINE uint32_t getB() const { return static_cast<uint32_t>(_b); }
  FOG_INLINE uint32_t getAB() const { return static_cast<uint32_t>(_ab); }

  // --------------------------------------------------------------------------
  // [Members]
  // --------------------------------------------------------------------------

  // Not ideal, but total size of one pair is only 64-bits and we support BMP
  // and SMP.

  uint64_t _a  : 21;
  uint64_t _b  : 21;
  uint64_t _ab : 22;
};

// ============================================================================
// [Fog::CharNormalizationCorrection]
// ============================================================================

struct FOG_NO_EXPORT CharNormalizationCorrection
{
  // --------------------------------------------------------------------------
  // [Accessors]
  // --------------------------------------------------------------------------

  FOG_INLINE uint32_t getCode() const { return _code; }
  FOG_INLINE uint32_t getOriginal() const { return _original; }
  FOG_INLINE uint32_t getCorrected() const { return _corrected; }
  FOG_INLINE uint32_t getVersion() const { return _version; }

  // --------------------------------------------------------------------------
  // [Members]
  // --------------------------------------------------------------------------

  //! @brief Unicode code point.
  uint32_t _code;
  //! @brief Original (deprecated) decomposition.
  uint32_t _original;
  //! @brief Corrected decomposition.
  uint32_t _corrected;
  //! @brief Version of unicode for which the correction was entered into the
  //! data.
  uint32_t _version;
};

// ============================================================================
// [Fog::CharISO15924Data]
// ============================================================================

struct FOG_NO_EXPORT CharISO15924Data
{
  // --------------------------------------------------------------------------
  // [Accessors]
  // --------------------------------------------------------------------------

  FOG_INLINE uint32_t getIso15924() const { return _iso15924; }
  FOG_INLINE uint32_t getScript() const { return _script; }

  // --------------------------------------------------------------------------
  // [Members]
  // --------------------------------------------------------------------------

  uint32_t _iso15924;
  uint32_t _script;
};

// ============================================================================
// [Fog::CharData]
// ============================================================================

//! @brief Character data (ASCII and UNICODE tables).
struct FOG_NO_EXPORT CharData
{
  // --------------------------------------------------------------------------
  // [Methods]
  // --------------------------------------------------------------------------

  // ${CHAR_METHODS_INLINE:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  enum
  {
    PO_BLOCK_SIZE = 128,
    PO_OFFSET_SHIFT = 7,
    PO_OFFSET_MASK  = 127
  };

  FOG_INLINE uint32_t getPropertyIndexUCS2(uint32_t ucs2) const
  {
    return offset[ucs2 >> PO_OFFSET_SHIFT] * PO_BLOCK_SIZE + (ucs2 & PO_OFFSET_MASK);
  }

  FOG_INLINE uint32_t getPropertyIndexUCS2Unsafe(uint32_t ucs2) const
  {
    return offset[ucs2 >> PO_OFFSET_SHIFT] * PO_BLOCK_SIZE + (ucs2 & PO_OFFSET_MASK);
  }

  FOG_INLINE uint32_t getPropertyIndexUCS4(uint32_t ucs4) const
  {
    // We assign invalid characters to NULL.
    if (ucs4 > UNICODE_MAX)
      ucs4 = 0; 

    return offset[ucs4 >> PO_OFFSET_SHIFT] * PO_BLOCK_SIZE + (ucs4 & PO_OFFSET_MASK);
  }

  FOG_INLINE uint32_t getPropertyIndexUCS4Unsafe(uint32_t ucs4) const
  {
    // Caller must ensure that ucs4 is in valid range.
    FOG_ASSERT(ucs4 <= UNICODE_MAX);

    return offset[ucs4 >> PO_OFFSET_SHIFT] * PO_BLOCK_SIZE + (ucs4 & PO_OFFSET_MASK);
  }

  FOG_INLINE const CharProperty& getPropertyUCS2(uint32_t ucs2) const
  {
    return property[getPropertyIndexUCS2(ucs2)];
  }

  FOG_INLINE const CharProperty& getPropertyUCS2Unsafe(uint32_t ucs2) const
  {
    return property[getPropertyIndexUCS2Unsafe(ucs2)];
  }

  FOG_INLINE const CharProperty& getPropertyUCS4(uint32_t ucs4) const
  {
    return property[getPropertyIndexUCS4(ucs4)];
  }

  FOG_INLINE const CharProperty& getPropertyUCS4Unsafe(uint32_t ucs4) const
  {
    return property[getPropertyIndexUCS4Unsafe(ucs4)];
  }

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_METHODS_INLINE:END}

  // --------------------------------------------------------------------------
  // [ASCII]
  // --------------------------------------------------------------------------

  //! @brief ASCII8 character type (classification).
  uint8_t asciiCType[256];
  //! @brief ASCII8 character to lowercase table.
  uint8_t asciiToLower[256];
  //! @brief ASCII8 character to uppercase table.
  uint8_t asciiToUpper[256];

  // --------------------------------------------------------------------------
  // [Unicode - UTF8 Size]
  // --------------------------------------------------------------------------

  //! @brief UTF-8 Length table useful when converting from UTF-8 to UCS-4.
  //!
  //! Let's take a UTF-8 byte sequence. The first byte in a sequence tells how
  //! long the sequence is. Let's call the subsequent decimal bytes [Z Y X W].
  //!
  //!   - Z => 0   && Z <= 127 [1] -> U = Z
  //!   - Z >= 128 && Z <= 191 [1] -> U = ERROR
  //!   - Z >= 192 && Z <= 223 [2] -> U = (Z-192)*64 + (Y-128)
  //!   - Z >= 224 && Z <= 239 [3] -> U = (Z-224)*4096 + (Y-128)*64 + (X-128)
  //!   - Z >= 240 && Z <= 247 [4] -> U = (Z-240)*262144 + (Y-128)*4096 + (X-128)*64 + (W-128)
  //!   - Z >= 248 && Z <= 255 [1] -> U = ERROR
  //!
  //! The table looks like this:
  //!   - 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  //!     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  //!     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  //!     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  //!     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  //!     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  //!     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  //!     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  //!     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  //!     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  //!     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  //!     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  //!     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  //!     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  //!     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  //!     4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0
  //!   - Zeros are invalid UTF-8 characters

  //! @brief UTF8 data.
  uint8_t utf8Size[256];

  // --------------------------------------------------------------------------
  // [Unicode - Offset]
  // --------------------------------------------------------------------------

  // ${CHAR_OFFSET_DECL:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  //! @brief Offset to the property block, see @c getCharProperty().
  uint8_t offset[8704];

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_OFFSET_DECL:END}

  // --------------------------------------------------------------------------
  // [Unicode - Char-Property]
  // --------------------------------------------------------------------------

  // ${CHAR_PROPERTY_DECL:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  //! @brief Unicode character properties, see @c getCharProperty().
  CharProperty property[29312];

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_PROPERTY_DECL:END}

  // --------------------------------------------------------------------------
  // [Unicode - Char-Info]
  // --------------------------------------------------------------------------

  // ${CHAR_INFO_DECL:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  //! @brief Character info data (see @ref CharProperty::infoIndex).
  CharInfo info[1256];

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_INFO_DECL:END}

  // --------------------------------------------------------------------------
  // [Unicode - Char-Special]
  // --------------------------------------------------------------------------

  // ${CHAR_SPECIAL_DECL:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  //! @brief Unicode special properties.
  CharSpecial special[108];

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_SPECIAL_DECL:END}

  // --------------------------------------------------------------------------
  // [Unicode - Char-Normalization Corrections]
  // --------------------------------------------------------------------------

  // ${CHAR_NORMALIZATION_CORRECTIONS_DECL:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  //! @brief Unicode normalization corrections.
  CharNormalizationCorrection normalizationCorrections[6];

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_NORMALIZATION_CORRECTIONS_DECL:END}
  
  // --------------------------------------------------------------------------
  // [Unicode - Char-Decomposition]
  // --------------------------------------------------------------------------

  // ${CHAR_DECOMPOSITION_DECL:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  //! @brief Decomposition data.
  uint16_t decomposition[10158];

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_DECOMPOSITION_DECL:END}

  // --------------------------------------------------------------------------
  // [Unicode - Char-Composition]
  // --------------------------------------------------------------------------

  // ${CHAR_COMPOSITION_DECL:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  //! @brief Composition id to composition data index mapping.
  uint16_t compositionIdToIndex[56];

  //! @brief Composition data.
  CharComposition compositionData[935];

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_COMPOSITION_DECL:END}

  // --------------------------------------------------------------------------
  // [Unicode - ISO-15924]
  // --------------------------------------------------------------------------

  // ${CHAR_ISO15924_DECL:BEGIN}
  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---

  //! @brief ISO-15924 From TEXT_SCRIPT.
  uint32_t iso15924FromTextScript[103];

  //! @brief TEXT_SCRIPT from ISO-15924.
  CharISO15924Data textScriptFromIso15924[105];

  // --- Auto-generated by generate-unicode.py (Unicode 6.1.0) ---
  // ${CHAR_ISO15924_DECL:END}
};

extern FOG_API const CharData _charData;

// ============================================================================
// [Implemented-Later]
// ============================================================================

FOG_INLINE const CharInfo& CharProperty::getInfo() const
{
  return _charData.info[getInfoIndex()];
}

FOG_INLINE const CharSpecial& CharProperty::getSpecial() const
{
  FOG_ASSERT(getMappingType() == CHAR_MAPPING_SPECIAL);
  return _charData.special[getMappingData()];
}

FOG_INLINE const uint16_t* CharProperty::getDecompositionData() const
{
  return &_charData.decomposition[_decompositionIndex];
}

// ============================================================================
// [Fog::Unicode]
// ============================================================================

namespace Unicode {

//! @addtogroup Fog_Core_Tools
//! @{

static FOG_INLINE uint32_t utf8GetSize(uint8_t c)
{
  return _charData.utf8Size[c];
}

static FOG_INLINE bool utf8IsValid(uint8_t c)
{
  return c < 0x80 && c >= 0xC0;
}

//! @}

} // Unicode namespace
} // Fog namespace

// [Guard]
#endif // _FOG_CORE_TOOLS_CHARDATA_H
