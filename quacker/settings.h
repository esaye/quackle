/*
 *  Quackle -- Crossword game artificial intelligence and analysis tool
 *  Copyright (C) 2005-2014 Jason Katz-Brown and John O'Laughlin.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QUACKER_SETTINGS_H
#define QUACKER_SETTINGS_H

#include <string>

#include <QWidget>
#include <QSettings>

class QComboBox;
class QCheckBox;
class QPushButton;

using namespace std;

class Settings : public QWidget
{
Q_OBJECT

public:
	Settings(QWidget *parent = 0);

	static Settings *self();

signals:
	void refreshViews();

public slots:
	// called before anything else to initialize quackle generally
	void preInitialize();

	// called to set up libquackle data structures and our internal
	// data structures based on stored user settings
	void initialize();

	// called to set widgets to display current settings based
	// on libquackle data structures and our internal data structures
	void load();

	void createGUI();

protected slots:
	void lexiconChanged(const QString &lexiconName);
	void alphabetChanged(const QString &alphabetName);
	void themeChanged(const QString &themeName);
	void boardChanged(const QString &boardName);

	void addBoard();
	void editBoard();
	void deleteBoard();
	
	void setQuackleToUseLexiconName(const string &lexiconName);
	void setQuackleToUseAlphabetName(const string &alphabetName);
	void setQuackleToUseThemeName(const QString &themeName);
	void setQuackleToUseBoardName(const QString &lexiconName);

protected:
	QComboBox *m_lexiconNameCombo;
	QComboBox *m_alphabetNameCombo;
	QComboBox *m_themeNameCombo;
	QComboBox *m_boardNameCombo;
	QPushButton *m_addBoard;
	QPushButton *m_editBoard;
	QPushButton *m_deleteBoard;
	QString m_dataDir;
	QString m_themeName;

private:
	// populate the popup based on what's in QSettings
	void loadBoardNameCombo();

	// load up an item list based on a list of filenames
	void populateListFromFilenames(QStringList& list, const QString &path);
	
	static Settings *m_self;
};

#endif
