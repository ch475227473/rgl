// C++ source
// This file is part of RGL.
//
// $Id: device.cpp 672 2008-05-13 12:52:09Z dmurdoch $
// ---------------------------------------------------------------------------
#include "Device.hpp"
#include "lib.hpp"
// ---------------------------------------------------------------------------
Device::Device(int id) : id_(id)
{
  scene   = new Scene();
  rglview = new RGLView(scene);
  window  = new Window( rglview, lib::getGUIFactory() );
  window->addDisposeListener(this);
}
// ---------------------------------------------------------------------------
Device::~Device()
{
  delete scene;
}
// ---------------------------------------------------------------------------
int  Device::getID() 
{
  return id_;
}
// ---------------------------------------------------------------------------
void Device::notifyDisposed(Disposable* disposable)
{
  dispose();
}
// ---------------------------------------------------------------------------
void Device::setName(const char* string)
{
  window->setTitle(string);
}
// ---------------------------------------------------------------------------
void Device::update()
{
//  window->update();
}
// ---------------------------------------------------------------------------
bool Device::open(void)
{
  window->setVisibility(true);
  return true;
}
// ---------------------------------------------------------------------------
void Device::close(void)
{
  window->close(); 
}
// ---------------------------------------------------------------------------

void Device::bringToTop(int stay)
{
  window->bringToTop(stay);
}

void Device::setWindowRect(int left, int top, int right, int bottom)
{
  window->setWindowRect(left, top, right, bottom);
}

void Device::getWindowRect(int *left, int *top, int *right, int *bottom)
{
  window->getWindowRect(left, top, right, bottom);
}

// ---------------------------------------------------------------------------
int Device::getIgnoreExtent(void)
{
  return scene->getIgnoreExtent();
}
// ---------------------------------------------------------------------------
void Device::setIgnoreExtent(int in_ignoreExtent)
{
  scene->setIgnoreExtent(in_ignoreExtent);
}
// ---------------------------------------------------------------------------
int Device::getSkipRedraw(void)
{
  return window->getSkipRedraw();
}
// ---------------------------------------------------------------------------
void Device::setSkipRedraw(int in_skipRedraw)
{
  window->setSkipRedraw(in_skipRedraw);
}
// ---------------------------------------------------------------------------
bool Device::clear(TypeID stackTypeID)
{
  bool success;
  success = scene->clear(stackTypeID);
  rglview->update();
  return success;
}
// ---------------------------------------------------------------------------
int Device::add(SceneNode* node)
{
  bool success;
  success = scene->add(node);
  rglview->update();
  if (success) return node->getObjID();
  else return 0;
}
// ---------------------------------------------------------------------------

bool Device::pop(TypeID stackTypeID, int id)
{
  bool success;
  if (rglview->windowImpl->beginGL()) { // Need to set context for display lists.
    success = scene->pop(stackTypeID, id);
    rglview->windowImpl->endGL();
  } else 
    success = false;
  rglview->update();
  return success;
}
// ---------------------------------------------------------------------------
bool Device::snapshot(int format, const char* filename)
{
  return rglview->snapshot( (PixmapFileFormatID) format, filename);
}
// ---------------------------------------------------------------------------
RGLView* Device::getRGLView(void)
{
  return rglview;
}
// ---------------------------------------------------------------------------
bool Device::postscript(int format, const char* filename, bool drawText)
{
  return rglview->postscript( format, filename, drawText);
}
// ---------------------------------------------------------------------------
void Device::getFonts(FontArray& outfonts, int nfonts, char** family, int* style, double* cex, 
                      bool useFreeType)
{
  window->getFonts(outfonts, nfonts, family, style, cex, useFreeType);
}
