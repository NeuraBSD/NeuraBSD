/****************************************************************************
** Meta object code from reading C++ file 'NavigationEngine.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "NavigationEngine.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NavigationEngine.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
	struct qt_meta_tag_ZN16NavigationEngineE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN16NavigationEngineE = QtMocHelpers::stringData(
"NavigationEngine",
"nextStep",
"",
"prevStep"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN16NavigationEngineE[] = {

	// content:
	12,       // revision
	0,       // classname
	0,    0, // classinfo
	2,   14, // methods
	0,    0, // properties
	0,    0, // enums/sets
	0,    0, // constructors
	0,       // flags
	0,       // signalCount

	// slots: name, argc, parameters, tag, flags, initial metatype offsets
	1,    0,   26,    2, 0x08,    1 /* Private */,
	3,    0,   27,    2, 0x08,    2 /* Private */,

	// slots: parameters
	QMetaType::Void,
	QMetaType::Void,

	0        // eod
};

Q_CONSTINIT const QMetaObject NavigationEngine::staticMetaObject = { {
	QMetaObject::SuperData::link<QWizardPage::staticMetaObject>(),
	qt_meta_stringdata_ZN16NavigationEngineE.offsetsAndSizes,
	qt_meta_data_ZN16NavigationEngineE,
	qt_static_metacall,
	nullptr,
	qt_incomplete_metaTypeArray<qt_meta_tag_ZN16NavigationEngineE_t,
	// Q_OBJECT / Q_GADGET
	QtPrivate::TypeAndForceComplete<NavigationEngine, std::true_type>,
	// method 'nextStep'
	QtPrivate::TypeAndForceComplete<void, std::false_type>,
	// method 'prevStep'
	QtPrivate::TypeAndForceComplete<void, std::false_type>
	>,
	nullptr
} };

void NavigationEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
	auto *_t = static_cast<NavigationEngine *>(_o);
	if (_c == QMetaObject::InvokeMetaMethod) {
		switch (_id) {
			case 0: _t->nextStep(); break;
			case 1: _t->prevStep(); break;
			default: ;
		}
	}
	(void)_a;
}

const QMetaObject *NavigationEngine::metaObject() const
{
	return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavigationEngine::qt_metacast(const char *_clname)
{
	if (!_clname) return nullptr;
	if (!strcmp(_clname, qt_meta_stringdata_ZN16NavigationEngineE.stringdata0))
	return static_cast<void*>(this);
	return QWizardPage::qt_metacast(_clname);
}

int NavigationEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
	_id = QWizardPage::qt_metacall(_c, _id, _a);
	if (_id < 0)
	return _id;
	if (_c == QMetaObject::InvokeMetaMethod) {
		if (_id < 2)
		qt_static_metacall(this, _c, _id, _a);
		_id -= 2;
	}
	if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
		if (_id < 2)
		*reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
		_id -= 2;
	}
	return _id;
}
QT_WARNING_POP
