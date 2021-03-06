/* Copyright 2013 David Axmark

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/*
 * WorkspaceLayout.h
 *
 *  Created on: Jan 31, 2013
 *      Author: Spiridon Alexandru
 */

#ifndef WORKSPACELAYOUT_H_
#define WORKSPACELAYOUT_H_

#include <maapi.h>
#include <MAUtil/util.h>

// Include all the wrappers.
#include <NativeUI/Widgets.h>
#include "ReloadUIListener.h"
#include "dataTypes.h"

using namespace NativeUI;
using namespace MAUtil;

class WorkspaceLayout:
	public VerticalLayout,
	public ListViewListener,
	public ButtonListener
{

public:
	/**
	 * Constructor.
	 * @param os The current os.
	 * @param orientation The current device orientation.
	 */
	WorkspaceLayout(MAUtil::String os, int orientation);

	/**
	 * Destructor.
	 */
	~WorkspaceLayout();

	/**
	 * Add a reload UI event listener.
	 * @param listener The listener that will receive reload UI events.
	 */
	void addReloadUIListener(ReloadUIListener* listener);

	/**
	 * Remove a reload UI listener.
	 * @param listener The listener that receives reload UI events.
	 */
	void removeReloadUIListener(ReloadUIListener* listener);

	/**
	 * If there is no list populates the List View Widget with the project data
	 * from mProjects vector. Else destroys and deallocates previous list items
	 * and creates new ones.
	 */
	void updateProjectList(MAUtil::Vector <reloadProject> * projects);

private:
	/**
	 * Creates and adds main layout to the screen.
	 */
	void createMainLayout();

    /**
	* This method is called if the touch-up event was inside the
	* bounds of the button.
	* @param button The button object that generated the event.
	*/
	virtual void buttonClicked(Widget* button);

	/**
	 * This method is called when a list view item is clicked.
	 * @param listView The list view object that generated the event.
	 * @param listViewItem The ListViewItem object that was clicked.
	 */
	virtual void listViewItemClicked(ListView * listView, int index );

	/**
	 * Sets the screen height/width values and the screen width ratio
	 * for the save and reload buttons.
	 */
	void setScreenValues();

private:

	/**
	 * The current screen orientation.
	 */
	int mCurrentOrientation;

	/**
	 * Array with login screen listeners.
	 */
	MAUtil::Vector<ReloadUIListener*> mReloadUIListeners;

	/**
	 * The button that refreshes the workspace project list.
	 */
	TextWidget* mRefreshButton;

	/**
	 * The button that disconnects us from the server.
	 */
	TextWidget *mDisconnectButton;

	/**
	 * Activity Indicato container that is shown when updating
	 * project list
	 */
	RelativeLayout *mActivityIndicatorContainer;

	/**
	 * The alphabetical list view.
	 */
	ListView* mListView;

	/**
	 * The platform the client is running on.
	 */
	MAUtil::String mOS;

	/**
	 * The device screen width.
	 */
	int mScreenWidth;

	/**
	 * The device screen height.
	 */
	int mScreenHeight;

	/**
	 * The save button screen width ratio.
	 */
	float mSaveButtonWidthRatio;

	/**
	 * The reload button screen width ratio.
	 */
	float mReloadButtonWidthRatio;

	/**
	 * Holds the List View index of the currently selected project
	 */
	int mSelectedProject;

	/**
	 * The save button widget
	 */
	TextWidget * mSaveButton;

	/**
	 * The reload Button widget
	 */
	TextWidget * mReloadButton;

	/**
	 * Holds the project name of the currently selected project
	 */
	MAUtil::String mSelectedProjectName;

	/**
	 * Stores the widget Height depending on the screen size
	 */
	int mWidgetHeight;
};

#endif /* WORKSPACELAYOUT_H_ */
