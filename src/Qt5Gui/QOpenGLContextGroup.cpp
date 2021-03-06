#include "QOpenGLContextGroup.hpp"
#include "../convert/callable.hpp"
#include "../thread.hpp"

#include <QOpenGLContextGroup>

void lua::QOpenGLContextGroup_metatable(const lua::index& mt)
{
    mt["shares"] = &QOpenGLContextGroup::shares;
}

int luaopen_Qt5Gui_QOpenGLContextGroup(lua_State* const state)
{
    lua::thread env(state);

    env["QOpenGLContextGroup"] = lua::value::table;
    env["QOpenGLContextGroup"]["currentContextGroup"] = &QOpenGLContextGroup::currentContextGroup;

    return 0;
}
