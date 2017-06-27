/*
 * Copyright 2017 Haiku, Inc.
 * Distributed under the terms of the MIT License.
 *
 * Author:
 *			Owen Pan <owen.pan@yahoo.com>
 */


#include "AddRemoveButtons.h"

#include <LayoutBuilder.h>

#include "FilerDefs.h"


AddRemoveButtons::AddRemoveButtons(uint32 add, uint32 remove, BView* target)
	:
	BView(NULL, B_WILL_DRAW)
{
	fAdd = new BButton("+");
	fRemove = new BButton("-");

	BMessage* msg = new BMessage(add);
	msg->AddPointer(kPointer, target);
	fAdd->SetMessage(msg);

	msg = new BMessage(remove);
	msg->AddPointer(kPointer, target);
	fRemove->SetMessage(msg);

	BFont font;
	GetFont(&font);
	float width = font.StringWidth("+-") * 2;
	BSize size(width, width);

	fAdd->SetExplicitSize(size);
	fRemove->SetExplicitSize(size);

	BLayoutBuilder::Group<>(this, B_HORIZONTAL, 0)
		.Add(fRemove)
		.Add(fAdd)
		.End();

	fAdd->SetToolTip("Add below");
	fRemove->SetToolTip("Remove");
}


AddRemoveButtons::~AddRemoveButtons()
{
	delete fAdd;
	delete fRemove;
}