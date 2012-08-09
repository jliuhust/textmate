#include <editor/editor.h>

class MarkTests : public CxxTest::TestSuite
{
public:
	void test_mark ()
	{
		// kSetMark
		// kDeleteToMark
		// kSelectToMark
		// kSwapWithMark

		ng::buffer_t buf;
		ng::editor_t editor(buf);
		editor.insert("Hello world");
		editor.perform(ng::kMoveToBeginningOfLine);
		editor.perform(ng::kMoveWordForward);
		editor.perform(ng::kSetMark);
		editor.perform(ng::kMoveToBeginningOfLine);
		editor.insert("Nice");
		TS_ASSERT_EQUALS(editor.as_string(), "NiceHello world");

		editor.perform(ng::kDeleteToMark);
		TS_ASSERT_EQUALS(editor.as_string(), "Nice world");

		editor.perform(ng::kMoveForward);
		editor.perform(ng::kSetMark);
		editor.perform(ng::kMoveToEndOfLine);
		editor.perform(ng::kSelectToMark);
		editor.insert("House");
		TS_ASSERT_EQUALS(editor.as_string(), "Nice House");

		editor.perform(ng::kSwapWithMark);
		editor.insert("Big ");
		TS_ASSERT_EQUALS(editor.as_string(), "Nice Big House");
	}
};
