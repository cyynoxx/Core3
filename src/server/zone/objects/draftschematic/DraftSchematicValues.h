/*
 *	server/zone/objects/draftschematic/DraftSchematicValues.h generated by engine3 IDL compiler 0.55
 */

#ifndef DRAFTSCHEMATICVALUES_H_
#define DRAFTSCHEMATICVALUES_H_

#include "engine/orb/DistributedObjectBroker.h"

class DraftSchematic;

class CraftingTool;

#include "engine/core/ManagedObject.h"

class DraftSchematicValues : public ManagedObject {
public:
	DraftSchematicValues();

	void addExperimentalProperty(const String& subtitle, const String& title, float min, float max, const int precision);

	String& getExperimentalPropertySubtitle(const int i);

	String& getExperimentalPropertySubtitle(const String& title, const int i);

	String& getExperimentalPropertyTitle(const String& subtitle);

	String& getExperimentalPropertyTitle(const int i);

	String& getExperimentalPropertySubtitleClass(const int i);

	int getExperimentalPropertySubtitleSize();

	int getExperimentalPropertySubtitleSize(const String& title);

	int getExperimentalPropertyTitleSize();

	bool hasProperty(const String& attribute);

	void setCurrentValue(const String& attribute, float value);

	void setCurrentValue(const String& attribute, float value, float min, float max);

	void setCurrentPercentage(const String& attribute, float value);

	void setCurrentPercentage(const String& attribute, float value, float min, float max);

	void setMaxPercentage(const String& attribute, float value);

	void lockValue(const String& attribute);

	void resetValue(const String& attribute);

	float getCurrentValue(const String& attribute);

	float getCurrentValue(const int index);

	float getCurrentPercentage(const String& attribute);

	float getCurrentPercentage(const int index);

	float getCurrentPercentageAverage(const int index);

	float getCurrentPercentageAverage(const String& title);

	float getMaxPercentage(const String& attribute);

	float getMaxPercentage(const int index);

	float getMaxPercentageAverage(const int index);

	int getValuesToSendSize();

	int getTitleLine(String& title);

	String& getValuesToSend(const int i);

	float getMinValue(const String& attribute);

	float getMaxValue(const String& attribute);

	void setMinValue(const String& attribute, float value);

	void setMaxValue(const String& attribute, float value);

	int getPrecision(const String& attribute);

	void setPrecision(const String& attribute, const int precision);

	void recalculateValues(DraftSchematic* draftSchematic);

	float getAttributeAndValue(DraftSchematic* draftSchematic, String& attribute, const int i);

	void clearAll();

	void clear();

	void toString();

protected:
	DraftSchematicValues(DummyConstructorParameter* param);

	virtual ~DraftSchematicValues();

	String _return_getExperimentalPropertySubtitle;
	String _return_getExperimentalPropertySubtitleClass;
	String _return_getExperimentalPropertyTitle;
	String _return_getValuesToSend;

	friend class DraftSchematicValuesHelper;
};

class DraftSchematicValuesImplementation;

class DraftSchematicValuesAdapter : public ManagedObjectAdapter {
public:
	DraftSchematicValuesAdapter(DraftSchematicValuesImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void addExperimentalProperty(const String& subtitle, const String& title, float min, float max, const int precision);

	String& getExperimentalPropertySubtitle(const int i);

	String& getExperimentalPropertySubtitle(const String& title, const int i);

	String& getExperimentalPropertyTitle(const String& subtitle);

	String& getExperimentalPropertyTitle(const int i);

	String& getExperimentalPropertySubtitleClass(const int i);

	int getExperimentalPropertySubtitleSize();

	int getExperimentalPropertySubtitleSize(const String& title);

	int getExperimentalPropertyTitleSize();

	bool hasProperty(const String& attribute);

	void setCurrentValue(const String& attribute, float value);

	void setCurrentValue(const String& attribute, float value, float min, float max);

	void setCurrentPercentage(const String& attribute, float value);

	void setCurrentPercentage(const String& attribute, float value, float min, float max);

	void setMaxPercentage(const String& attribute, float value);

	void lockValue(const String& attribute);

	void resetValue(const String& attribute);

	float getCurrentValue(const String& attribute);

	float getCurrentValue(const int index);

	float getCurrentPercentage(const String& attribute);

	float getCurrentPercentage(const int index);

	float getCurrentPercentageAverage(const int index);

	float getCurrentPercentageAverage(const String& title);

	float getMaxPercentage(const String& attribute);

	float getMaxPercentage(const int index);

	float getMaxPercentageAverage(const int index);

	int getValuesToSendSize();

	int getTitleLine(String& title);

	String& getValuesToSend(const int i);

	float getMinValue(const String& attribute);

	float getMaxValue(const String& attribute);

	void setMinValue(const String& attribute, float value);

	void setMaxValue(const String& attribute, float value);

	int getPrecision(const String& attribute);

	void setPrecision(const String& attribute, const int precision);

	void recalculateValues(DraftSchematic* draftSchematic);

	float getAttributeAndValue(DraftSchematic* draftSchematic, String& attribute, const int i);

	void clearAll();

	void clear();

	void toString();

protected:
	String _param0_addExperimentalProperty__String_String_float_float_int_;
	String _param1_addExperimentalProperty__String_String_float_float_int_;
	String _param0_getExperimentalPropertySubtitle__String_int_;
	String _param0_getExperimentalPropertyTitle__String_;
	String _param0_getExperimentalPropertySubtitleSize__String_;
	String _param0_hasProperty__String_;
	String _param0_setCurrentValue__String_float_;
	String _param0_setCurrentValue__String_float_float_float_;
	String _param0_setCurrentPercentage__String_float_;
	String _param0_setCurrentPercentage__String_float_float_float_;
	String _param0_setMaxPercentage__String_float_;
	String _param0_lockValue__String_;
	String _param0_resetValue__String_;
	String _param0_getCurrentValue__String_;
	String _param0_getCurrentPercentage__String_;
	String _param0_getCurrentPercentageAverage__String_;
	String _param0_getMaxPercentage__String_;
	String _param0_getTitleLine__String_;
	String _param0_getMinValue__String_;
	String _param0_getMaxValue__String_;
	String _param0_setMinValue__String_float_;
	String _param0_setMaxValue__String_float_;
	String _param0_getPrecision__String_;
	String _param0_setPrecision__String_int_;
	String _param1_getAttributeAndValue__DraftSchematic_String_int_;
};

class DraftSchematicValuesHelper : public DistributedObjectClassHelper, public Singleton<DraftSchematicValuesHelper> {
	static DraftSchematicValuesHelper* staticInitializer;

public:
	DraftSchematicValuesHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<DraftSchematicValuesHelper>;
};

#include "engine/core/ManagedObjectImplementation.h"

class DraftSchematicValuesServant : public ManagedObjectImplementation {
public:
	DraftSchematicValues* _this;

public:
	DraftSchematicValuesServant();
	virtual ~DraftSchematicValuesServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*DRAFTSCHEMATICVALUES_H_*/
