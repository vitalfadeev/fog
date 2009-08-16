// [Fog/UI Library - C++ API]
//
// [Licence] 
// MIT, See COPYING file in package

// [Guard]
#ifndef _FOG_UI_BOXLAYOUT_H
#define _FOG_UI_BOXLAYOUT_H

// [Dependencies]
#include <Fog/UI/Layout.h>

//! @addtogroup Fog_UI
//! @{

namespace Fog {

// ============================================================================
// [Fog::BoxLayout]
// ============================================================================

//! @brief Base class for all layouts.
struct FOG_API BoxLayout : public Layout
{
  FOG_DECLARE_OBJECT(BoxLayout, Layout)

  // [Construction / Destruction]

  BoxLayout();
  virtual ~BoxLayout();

  virtual void reparentChildren();

  sysint_t indexOf(LayoutItem* item);

  bool addItem(LayoutItem* item);
  bool addItemAt(sysint_t index, LayoutItem* item);

  LayoutItem* takeAt(sysint_t index);

  bool deleteItem(LayoutItem* item);
  bool deleteItemAt(sysint_t index);

  Vector<LayoutItem*> items() const;

  FOG_INLINE int margin() const { return _margin; }
  FOG_INLINE int spacing() const { return _spacing; }

  void setMargin(int margin);
  void setSpacing(int spacing);

protected:
  Vector<LayoutItem*> _items;

  int _margin;
  int _spacing;
};

} // Fog namespace

//! @}

// [Guard]
#endif // _FOG_UI_BOXLAYOUT_H
