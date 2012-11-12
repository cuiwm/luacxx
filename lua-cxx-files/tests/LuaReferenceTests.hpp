#include <QtTest/QtTest>
#include "Lua.hpp"
#include "LuaStack.hpp"
#include "LuaGlobal.hpp"
#include "LuaReference.hpp"
#include "LuaReferenceAccessible.hpp"
#include "LuaGlobalAccessible.hpp"

using namespace std;

class LuaReferenceTests : public QObject
{
    Q_OBJECT
private slots:

    void testLuaHandlesReferencesProperly()
    {
        Lua lua;
        LuaStack s(lua);
        s << "No Time";
        LuaReference r = s.save();
        QVERIFY(s.size() == 0);
        s << r;
        QVERIFY(s.qstring() == "No Time");
    }

    void testAccessibleCanGetAReference()
    {
        Lua lua;
        LuaReferenceAccessible accessor(lua);
        LuaStack s(lua);
        s << "No Time";
        accessor.store(s);
        QVERIFY(s.qstring() == "No Time");
        s.clear();
        accessor.push(s);
        QVERIFY(s.qstring() == "No Time");
    }

    void testAccessibleCanGetAGlobal()
    {
        Lua lua;
        LuaGlobalAccessible accessor(lua, "foo");
        LuaStack s(lua);
        s << "No Time";
        accessor.store(s);
        QCOMPARE((const char*)lua["foo"], "No Time");
        s.clear();
        accessor.push(s);
        QVERIFY(s.qstring() == "No Time");
    }

};