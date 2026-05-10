#pragma once

/*
 *   ____    ____    ____    ______  __  __  __     ______  ____    ____    ______  ______  ______   __  __  ____    ____
 *  /\  _`\ /\  _`\ /\  _`\ /\  _  \/\ \/\ \/\ \   /\__  _\/\  _`\ /\  _`\ /\__  _\/\__  _\/\__  _\ /\ \/\ \/\  _`\ /\  _`\
 *  \ \ \/\ \ \ \L\_\ \ \L\_\ \ \L\ \ \ \ \ \ \ \  \/_/\ \/\ \,\L\_\ \ \L\_\/_/\ \/\/_/\ \/\/_/\ \/ \ \ `\\ \ \ \L\_\ \,\L\_\
 *   \ \ \ \ \ \  _\L\ \  _\/\ \  __ \ \ \ \ \ \ \  __\ \ \ \/_\__ \\ \  _\L  \ \ \   \ \ \   \ \ \  \ \ , ` \ \ \L_L\/_\__ \
 *    \ \ \_\ \ \ \L\ \ \ \/  \ \ \/\ \ \ \_\ \ \ \L\ \\ \ \  /\ \L\ \ \ \L\ \ \ \ \   \ \ \   \_\ \__\ \ \`\ \ \ \/, \/\ \L\ \
 *     \ \____/\ \____/\ \_\   \ \_\ \_\ \_____\ \____/ \ \_\ \ `\____\ \____/  \ \_\   \ \_\  /\_____\\ \_\ \_\ \____/\ `\____\
 *      \/___/  \/___/  \/_/    \/_/\/_/\/_____/\/___/   \/_/  \/_____/\/___/    \/_/    \/_/  \/_____/ \/_/\/_/\/___/  \/_____/
 *
 *                                               Jackal Client Default Settings.
 *                                                        Wormwaker.
 */

#define NAMED_COLOR_BASE_LIST \
"Black", "Gray", "White", "Red", "Gold", "Yellow", "Green", "Dark Green", "Aqua", "Blue", "Magenta", "Pink", "Purple", "Pink-Magenta", "Red-Orange", "White-Gray", "Aqua-Blue", "Aqua-Pink", "Green-Red", "Astrolfo", "Colorful", "Rainbow"

#define COMBOBOX(defval, ...)	\
							{{"Options", __VA_ARGS__}, {"Selected", defval}}



#define MAKE_COMBOBOX(name, defval, ...)	\
						{name,						\
							{		\
								{"Options", __VA_ARGS__},\
								{"Selected", defval}		\
							}\
						}

//#define MAKE_COMBOBOX(name, options, defval)		\
//					{name, json::parse("{\"Options\":"s + unquote(#options) + ",\"Selected\":"s + #defval + "}")}
					//{name, {{"Options", options}, {"Selected", defval}}}

#define MAKE_SOUNDITEM(name, defval)	\
						MAKE_COMBOBOX(name, defval, \
						{"Off", "toast.wav", "bassattack.wav", "pling.wav", "pling_low.wav", "bell.wav", "icechime.wav", \
						"enable.wav", "disable.wav", "rise_enable.wav", "rise_disable.wav", "quickmacro_enable.wav", "quickmacro_disable.wav", "sigma_enable.wav", "sigma_disable.wav", "steam_toast.wav", "steam_show_modal.wav", "steam_menu_in.wav", "steam_menu_out.wav", "steam_warning.wav", "steam_confirm_negative.wav", "steam_confirm_positive.wav",\
						\
						}	\
						)

#define WORMWAKER_MID  XorStringA("3494361276877525")
#define WORRNWAKER_MID  XorStringA("3546682383928268")

json config_default_jsons
{
	{"Modules",
		{

			{"Anti Close",
				{
					{"Notify Close Message", true}
				}
			},

			{"Anti Debug",
				{
					{"Async", true},
					{"Active Defense", true},
					{"Check Cooldown", 500},
					{"Related File Detection", true},

					/*{"Reaction",
						{
							{"Options", {"Warn", "Exit", "Self Destruct", "Extinction"}},
							{"Selected", "Exit"}
						}
					},*/

					MAKE_COMBOBOX("Reaction", "Exit",
						{"Warn", "Exit", "Self Destruct", "Extinction"})

						/*{"Immediate Exit", true},
						{"Self Destruct (EXE)", false},
						{"Extinction (Entire Client)", false}*/
				}
			},

			{"Anti Inject",
				{
					{"Async", true},
					{"Check Cooldown", 2000U},
					{"Exclude Verified", false},
					{"Exclude DLLs in Release", true},
					{"Monitor Modules", true},
					{"Auto Unload", false},
					{"Exit If Unload Failed", false},
				}
			},

			{"Anti Intercept",
				{
					{"Keep Alive", false}
				}
			},

			{"Anti MouseHook",
				{
					{"bind", {{"Keybind", {VK_RCONTROL, 'M'}}}}
				}
			},

			{"Anti Taskkill",
				{
					{"Check Tskill.exe", false},
					{"Only Threat For Client", true},
					{"Notify Success", true},
					{"Notify Failure", true},
				}
			},

			{"Auto Start",
				{
					{"Async", true},
					{"Check Cooldown (ms)", 30000L},

					MAKE_COMBOBOX("Method", "Registry",
						{"Registry", "Service", "Scheduled Task"}
						),

					{"Registry Value Name", "JackalClient"},
					MAKE_COMBOBOX("Registry View", "Native",
						{"Native", "32-bit", "64-bit"}
						),
					//{"Service Name", "JackalClient"},
					{"Service Description", "Jackal Client Auto Start Service"},
					{"Service Display Name", "Jackal Client Service"},
					{"Service Stopping Timeout (s)", 10},
					{"Scheduled Task Name", "JackalClient"},
					{"Extra Arguments", ""},
				}
			},

			{"Admin",
				{
					
				}
			},

			{"System",
				{
					MAKE_COMBOBOX("System Privilege Check Method", "Whoami",
						{"Membership", "Whoami"}),

					{"Use NSudo", false},
				}
			},

			{"Trusted Installer",
				{
					{"Use NSudo", false},
				}
			},

			{"UAC Bypass",
				{
					{"Exit After Run", true},

					MAKE_COMBOBOX("Method", "Computerdefaults Legit",
						{"Computerdefaults",
						"Computerdefaults Legit",
						"Fodhelper",
						"Fodhelper Legit",
						"Cmstp",
						"PCA (PRO)",
						"Sdclt",
						"Sdclt Legit",
						"Slui",
						"Slui Legit",
						}),

					{"Close Menu", true},
					{"Legit Transparent Window", true},
					{"Cmstp Window Search Timeout (ms)", 10000},
					{"Safe Check", true},
				}
			},

			{"Super Topmost",
				{
					{"Main Window", true},
					{"Console Window", false},
				}
			}, 

			{"Auto UAC",
				{
					{"Notify", true},
					{"Quit After Click", true},
					{"Mouse Move Acceleration", 0.3f},
				}
			},

			{"Crack Password",
				{
					{"Async", true},
					{"Multithread", true},
					{"Memorize Prev Password", true},
					{"HUD", true},
					{"HUD Show Current Password Attempt", true},
					{"Hide HUD When Menu On", false},
					{"Use Strong Password Dictionary", true},
					{"Try Birthdays", true},
					{"Notify Password", true},
					{"Notify Speed", true},

					MAKE_COMBOBOX("Account Lockout Threshold Policy",
						"Query",
						{"Ignore", "Safe", "Query"}),

					{"Threshold Setting Confirmation MessageBox Timeout (ms)", 20000},

					MAKE_COMBOBOX("Threshold Setting Default Option", "Cancel",
						{"Yes", "No", "Cancel"}),
				}
			},

			{"Set Password",
				{
					{"Async", true},
					{"Async Single Instance", true},
					{"Just Clear", true},
					{"Or Custom Password:", "123456"},
					{"Auto Fill Username", true},
					{"Or Custom Username:", "Administrator"},
					{"Close Menu", true}
				}
			},

			{"Crash Key",
				{
					MAKE_COMBOBOX("Keyboard Device", "All",
						{"All", "PS/2", "USB", "Hyper-V"}),
				}
			},

			{"Reg Monitor",
				{
					MAKE_COMBOBOX("HKEY", "HKEY_LOCAL_MACHINE",
						{
							"HKEY_LOCAL_MACHINE", "HKEY_CURRENT_USER", "HKEY_CLASSES_ROOT", "HKEY_CURRENT_CONFIG", "HKEY_USERS"
						}),

					{"Path", ""s},
					{"Item Filter RegExp", ""s},
					{"Key Filter RegExp", ""s},
					{"Value Filter RegExp", ""s},
					{"Cooldown (ms)", 1000U},
				}
			},

			{"List Hijacks",
				{
					{"Async", true},
					{"Auto Console", true},

					MAKE_COMBOBOX("Notify Mode", "Console Output",
						{"Console Output", "Notify"})
				}
			},

			{"Kill Hijacks",
				{
					{"Async", true},
				}
			},

			{"Uninstaller",
				{
					MAKE_COMBOBOX("Victim", "None",
						{"None", "360", "Huorong"}),

					MAKE_COMBOBOX("Mode", "Auto",
						{"Auto", "Manual"}),

					MAKE_COMBOBOX("Uninstall Start Method", "Injection",
						{"Execute", "Parent Spoof", "Cmd Legit", "Explorer Legit", "Injection"}),

					{"Transparent Window", false},
					{"Notify Steps", true},
				}
			},

			{"Interceptor",
				{

				}
			},

#define MAKE_GATEKEEPER_ITEM(name, defval)	\
				MAKE_COMBOBOX(name, defval, {"Allow", "Query", "Deny"})

{"Gatekeeper",
   {
	   {"Use Loader to Inject (Suggested)", true},
	   {"Check Working Cooldown", 5000U},
	   {"Disable When Quit", true},
	   {"Comm File Check Cooldown (ms)", 200L},
	   //{"Confirmation Popups", true},
	   MAKE_GATEKEEPER_ITEM("Admin", "Allow"),
	   MAKE_GATEKEEPER_ITEM("Shutdown", "Query"),
	   MAKE_GATEKEEPER_ITEM("Reboot", "Query"),
	   MAKE_GATEKEEPER_ITEM("Logoff", "Query"),
	   MAKE_GATEKEEPER_ITEM("Win + L", "Query"),
	   MAKE_GATEKEEPER_ITEM("Ctrl + Shift + Esc", "Allow"),
	   MAKE_GATEKEEPER_ITEM("Ctrl + Alt + Del", "Query"),
	   MAKE_GATEKEEPER_ITEM("Sticky Keys", "Query"),
	   MAKE_GATEKEEPER_ITEM("Filter Keys", "Query"),
	   MAKE_GATEKEEPER_ITEM("Magnifier", "Query"),
	   MAKE_GATEKEEPER_ITEM("Narrator", "Query"),
	   MAKE_GATEKEEPER_ITEM("Projection Menu", "Query"),
	   MAKE_GATEKEEPER_ITEM("Accessibility", "Query"),
   }
},

{"No Firewall",
	{
		{"Masquerade", true},
		{"Domain", true},
		{"Private", true},
		{"Public", true},
	}
},

{"Privileges",
	{
		{"Notify", true},
	}
},

{"Machine Lock",
	{
		{"Title", "计算机已锁定"},
		{"Subtitle", "你需要输入密码"},

		{"Title Display", true},
		{"Subtitle Display", true},

		{"Background Color", "40;0;0;250"},
		{"Title Color", "yellow"},
		{"Subtitle Color", "aqua"},
		{"Password Color", "green"},

		{"Title Font Size", 180},
		{"Subtitle Font Size", 100},
		{"Password Font Size", 220},

		{"Mute", true},
		{"Disable IME", true},
		{"Keep Active", true},
		{"Force Topmost", true},
		{"Hide Taskbar", true},
		{"Disable KeyLogger", true},
		{"Disable Logoff", true},
		{"Pause Keystrokes2", true},

		MAKE_COMBOBOX("Mouse Lock", "Allow Move",
			{"Off", "Allow Move", "Disable All"}),

		{"Keyboard Lock (Ctrl, Win, Alt)", true},
		{"Disable Client Other Control", true},
		{"Disable Client Other HUD", true},

		MAKE_COMBOBOX("Emergency Escape Method", "Custom Hotkey (Notice Keyboard Lock)",
			{"Off", "Esc (Press 20 seconds)", "Custom Hotkey (Notice Keyboard Lock)"}),

		{"Custom Escape Hotkey", {{"Keybind", {VK_OEM_3}}}},

		MAKE_COMBOBOX("Exit Condition", "Password",
			{"Password", "Wait Duration"/*, "Wait Until"*/}),

		{"Password", "0721"},
		/*{"Password Attempt Threshold", 3U},
		{"Password Attempt Freeze Duration (min)", 5U},*/

		{"Wait Duration (min)", 30U},
		//{"Wait Until (HH:MM)", "00:00"},

		{"AUTO ENABLE WHEN CLIENT LAUNCHED", false},
	}
},

	{ "Shutdown",
		{
			{"Force", false},
			{"Power Off", true},

			MAKE_COMBOBOX("Method", "WINAPI",
				{"Command", "WINAPI", "NTAPI"})

				/*{"Method",
					{
						{"Options", {"Command", "WINAPI", "NTAPI"}},
						{"Selected", "WINAPI"}
					}
				}*/
		}
	},
	//{"Use Private API (Violence)", false}
	//MAKE_COMBOBOX("Method", ({"Command", "WINAPI", "NTAPI"}), "WINAPI")}

	{ "Reboot",
		{
			MAKE_COMBOBOX("Method", "WINAPI",
			{"Command", "WINAPI"}),

			{"Force", false}
		}
	},

	{ "Log Off",
		{
			MAKE_COMBOBOX("Method", "WINAPI",
			{"Command", "WINAPI"}),
			
			{"Force", false}
		}
	},

	{ "Crash",
		{
			{"Custom Win32 Error Code", 28},
		}
	},

		{"Message Blocker",
			{
				{"Notify", true},
				{"Disable When Quit", true},
				{"Output Messages", true},

				{"Ignore WM_PAINT", true},
				{"Ignore WM_TIMER", false},
				{"Ignore WM_QUIT", false},

				{"Overlay", true},
				MAKE_COMBOBOX("Overlay Color", "Red",
					{NAMED_COLOR_BASE_LIST}),
				{"Overlay Opacity (0~1)", 0.2f},
				{"Hide HUD When Menu On", false},

				MAKE_COMBOBOX("Target Window", "Foreground",
					{"Foreground", "PointAt"}),

					/*{"Auto Disable", false},
					TODO:	blink hud...
					*/
			}
		},

		{"Window ESP",
			{
				MAKE_COMBOBOX("Box Color", "Rainbow",
					{"Flow", NAMED_COLOR_BASE_LIST}),

				{"Box Line Width", 3.0f},
				{"Box Alpha", 0.5f},
				{"Exclude Invisible", true},
				{"Exclude Foreground", true},
				{"Exclude Pointed", true},
				{"Hide HUD When Menu On", true},
			}
		},

		{"Window Highlight",
			{
				{"Easing", true},
				{"Easing Speed (0~1)", 0.2f},
				{"Only Foreground", false},
				{"Aura Target Highlight", true},
				{"Endangered Excla Mark", true},
				{"Hide When Menu On", true},

				MAKE_COMBOBOX("Color", "Rainbow",
				{"Flow", NAMED_COLOR_BASE_LIST}),

				{"Dark Background", true},

				MAKE_COMBOBOX("Dark Background Color", "Black",
				{"Flow", NAMED_COLOR_BASE_LIST}),

				{"Dark Background Alpha (0~1)", 0.5f},

				{"Rectangle", true},
				{"Exclude Window Shadow", true},
				{"Opacity (0~1)", 0.9f},
				{"Round Corners", true},
				{"Roundness (0~1)", 0.05f},
#ifdef PROFESSIONAL_VERSION
				{"Glow (PRO)", true},
#else
				{"Glow (PRO)", false},
#endif
				{"Glow Thickness", 8.0f},
				{"Glow Opacity (0~1)", 0.6f},

				{"Switch Delay Enabled", true},
				{"Switch Delay (ms)", 250L},

#ifdef PROFESSIONAL_VERSION
				{"Blur Background Enabled (PRO)", false},
#else
				{"Blur Background Enabled (PRO)", false},
#endif
				{"Blur Background Opacity (0~1)", 1.0f},
			}
		},

		{"Tracers",
			{
				MAKE_COMBOBOX("Line Color", "Rainbow",
					{"Flow", NAMED_COLOR_BASE_LIST}),

				{"Line Width", 1.0f},
				{"Line Opacity (0~1)", 0.5f},
				{"Window Point X Rate", 0.5f},
				{"Window Point Y Rate", 0.05f},
			}
		},

		{"Opacity Changer",
			{
				MAKE_COMBOBOX("HUD", "Giant",
					{"Off", "Giant", "Rainbow Giant"}),

				MAKE_COMBOBOX("Shortcut", "Wheel on Side",
					{"Wheel on Side", "HotKey + Wheel"}),

				MAKE_COMBOBOX("Wheel Side", "Left",
					{"Left", "Top", "Right", "Bottom"}),

				{"Wheel Detect Only If Cursor Visible", true},

				MAKE_COMBOBOX("Target Window", "Foreground",
					{"Foreground", "PointAt"}),

				{"Wheel Hotkey", {{"Keybind", {VK_LMENU}}}},
				

				{"Hide HUD When Menu On", false},
				{"Temp HUD Duration (ms)", 3000L},
				{"Temp HUD Animation Duration (ms)", 300L},
				{"Step (%%)", 10U},
			}
		},

			{ "Window Master",
				{
					{"Hide HUD When Menu On", true},
					{"HUD Font Size", 20},
					{"HUD Line Gap", 5},

					MAKE_COMBOBOX("HUD Background", "Fancy",
					{"Off", "Simple", "Fancy"}),

					{"Easing", true},
					{"Easing Speed (0~1)", 0.1},	// 缓动速率

					MAKE_COMBOBOX("HUD Color", "Rainbow",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Target", "Foreground",
						{"Foreground", "PointAt"}),

					MAKE_COMBOBOX("Privacy Mode", "Invisible (>= Win10)",
						{"Black", "Invisible (>= Win10)"}),

						/*{"Show Texts", true}*/
					MAKE_COMBOBOX("HUD", "Follow",
							{"Off", "Follow", "BottomRight", "BottomLeft"}),

					MAKE_COMBOBOX("HUD Paging", "Off",
						{"Off", "Multiple Pages", "Only Show Page 1"}),

					{"HUD Item Count Per Page", 11U},
					{ "HUD Next Page", {{"Keybind", {VK_LMENU, VK_RIGHT}}} },
					{ "HUD Prev Page", {{"Keybind", {VK_LMENU, VK_LEFT}}} },

					{"Phantom Window Opacity (0~1)", 0.1f},

					{ "Privacy/U Keybind", {{"Keybind", {VK_LMENU, VK_F1}}} },
					{ "Privacy Overlay/U Keybind", {{"Keybind", {VK_LMENU, VK_F2}}} },
					{ "Toggle Phantom Window Keybind", {{"Keybind", {0}} }},
					{ "Kill Process Keybind", {{"Keybind", {VK_LMENU, VK_F3}} }},
					{ "EndTask Keybind", {{"Keybind", {VK_LMENU, VK_F9}}} },
					{ "Freeze/U Keybind", {{"Keybind", {VK_LMENU, VK_F6}}} },
					{ "Process Freeze/U Keybind", {{"Keybind", {VK_LMENU, VK_F7}}} },
					{ "Topmost/U Keybind", {{"Keybind", {VK_LMENU, VK_F8}}} },
					{ "Hide/Show Keybind", {{"Keybind", {VK_LMENU, VK_F5}}} },
					{ "Destroy Keybind", {{"Keybind", {VK_LMENU, VK_F11}}} },
					{ "Update Keybind", {{"Keybind", {0}}} },
					{ "Lock Update Keybind", {{"Keybind", {VK_LMENU, VK_F10}}} },
					{ "EndSession Keybind", {{"Keybind", {VK_LMENU, VK_F12}}} },
					{ "Sink Keybind", {{"Keybind", {0}}} },

				}
			},

			{"Private Window",
				{
					{"Async", true},

					MAKE_COMBOBOX("Mode", "Invisible (>= Win10)",
						{"Black", "Invisible (>= Win10)"}),

					MAKE_COMBOBOX("Policy", "Simple Check",
						{"Set Once", "Simple Check", "Complete Check", "Blatant Apply"}),

					{"Keep Checking Cooldown (ms)", 1000U},

					{"QQ NT", true},
					{"WeChat", true},
					{"WeChat New", true},
					{"Edge", true},
					{"Steam", true},
					{"Bilibili Desktop", true},

					{"Edge Overlay Mode", false},
					{"Clear Overlay Windows When Disabling", false},
					{"Notify Each Window Affinity Result", true},
					{"Record Window When Failed", true}
				}
			},

			{"Console ESP",
				{
					{"Check Cooldown (ms)", 500U},
					{"Monitor Console Created", true},
					{"Monitor Console Destroyed", true},
					{"Monitor Console Content", true},

					{"Process Blacklist (Sep With Semicolon)", "cmd.exe;git.exe;tesseract.exe;MSBuild.exe;JackalClient.exe;AppProvisioningPlugin.exe;clash-core-service.exe;postgres.exe"},

					MAKE_COMBOBOX("Notify Mode (Created/Destroyed)", "Console Output",
						{"Off", "Console Output", "Notify", "Chatter", "Actionbar", "Title", "Speak"}),

					MAKE_COMBOBOX("Notify Mode (Content)", "Console Output",
						{"Off", "Console Output", "File Output", "Notify", "Chatter", "Actionbar", "Title", "Speak"}),

					MAKE_COMBOBOX("Actionbar Color (Created)", "Dark Green",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Actionbar Color (Destroyed)", "Red",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Actionbar Color (Content)", "Colorful",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Chatter Color (Created)", "Dark Green",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Chatter Color (Destroyed)", "Red",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Chatter Color (Content)", "Gray",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Title Color (Created)", "Dark Green",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Title Color (Destroyed)", "Red",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Title Color (Content)", "Gray",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Target Mode (Content)", "Single",
						{"Single", "All"}),

					MAKE_COMBOBOX("Target Single Process (Content)", "", {""}),
				}
			},

			{ "Band Setter",
				{
					MAKE_COMBOBOX("Target", "Foreground",
						{"Foreground", "PointAt"}),

					MAKE_COMBOBOX("Operation", "Auto", 
						{"Auto", "Set", "Reset"}),

					{"Sync Topmost Status", true},

					MAKE_COMBOBOX("Z-Order Band", "UIAccess",
						{"Desktop", "UIAccess", "Immersive IHM", "Immersive Notification", "Immersive AppChrome", "Immersive MoGo", "Immersive Edgy", "Immersive InactiveMoBody", "Immersive InactiveDock", "Immersive ActiveMoBody", "Immersive ActiveDock", "Immersive Background", "Immersive Search", "Genuine Windows", "Immersive Restricted", "System Tools", "Lock Screen", "Above Lock UX"}),
				}
			},

			{"Topmost",
				{
					MAKE_COMBOBOX("Target", "Foreground",
						{"Foreground", "PointAt"}),

					MAKE_COMBOBOX("Operation", "Auto",
						{"Auto", "Topmost", "Untopmost"}),

					{"Notify", true},
				}
			},

			{"Title Changer",
				{
					{"Keep", true},
					{"Check Cooldown", 250L},

					MAKE_COMBOBOX("Pattern", "Word Replace",
						{"Clear", "Fixed", "Random", "Timestamp", "Word Replace"}),

					MAKE_COMBOBOX("Target", "Foreground",
						{"Foreground", "PointAt"}),

					{"Fixed Title", "Chrome Legacy Window"},

					{"Word Replace Old", "LiquidBounce"},
					{"Word Replace New", "WaterShadow"},
				}
			},

			{"Messenger",
				{
					{"Show Parameter Details", true},

					{"Blacklist Enabled", true},
					{"Blacklist (Sep With Semicolon)", "WM_NULL;WM_MOUSEFIRST;WM_NCHITTEST;WM_SETCURSOR;WM_GETTEXT;WM_WINDOWPOSCHANGING;WM_WINDOWPOSCHANGED"},

					{"Whitelist Enabled", false},
					{"Whitelist (Sep With Semicolon)", ""},

					MAKE_COMBOBOX("Notify Mode", "Console Output",
					{"Console Output", "Notify", "Chatter", "Actionbar", "Title"}),
				}
			},

			{"Toast ESP",
				{
					MAKE_COMBOBOX("Notify Mode", "Notify",
						{"Off", "Notify", "Chatter", "Title", "Speak", "Island", "Actionbar", "ChatBar"}),
					{"Exclude Client", true},
				}
			},

			{"Keyword ESP",
				{
					{"Keyword List (Sep With Semicolon)", string("")},
					MAKE_COMBOBOX("Target", "Screen",
						{"Screen", "Foreground", "PointAt"}),
					{"Recognize Cooldown (ms)", 1200L},

					{"Screen Mode Exclude Client", false},
					MAKE_COMBOBOX("Box Color", "Red",
						{"Flow", NAMED_COLOR_BASE_LIST}),
					{"Box Size Rate", 0.3f},
					{"Box Opacity", 0.9f},
					{"Box Thickness", 3.0f},
					{"Recognize Min Confidence (0~100)", 50.0f},
					MAKE_COMBOBOX("Show Confidence", "Float",
						{"Off", "Float", "Percentage"}),
					{"Confidence Opacity", 0.9f},
					{"Confidence Font Size", 40.0f},
					MAKE_COMBOBOX("Confidence Color", "Red",
						{"Flow", NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Fade", "Move",
						{"Off", "Normal", "Move"}),
					{"Dynamic Opacity", true},
					{"Accurate Box", true},
				}
			},

			{"Better Animation",
				{
					{"Animation Duration (ms)", 300L},
					{"Toggle NoAnimation Module", true},

					MAKE_COMBOBOX("Custom Style", "Fade",
						{"Fade", "Color Transition"/*, "Image Transition"*/}),

					{"Color Transition", "1;1;1"},
					//{"Image Path", ""},

					MAKE_COMBOBOX("Notify Mode", "Off",
						{"Off", "Notify", "Chatter", "Actionbar"}),

					{"Check Cooldown (ms)", 10L},
				}
			},

			{"Target ESP",
				{
					MAKE_COMBOBOX("Target", "PointAt",
						{"Target HUD", "Foreground", "PointAt", "it (Pronoun)"}),

					{"Rotation Speed", 1.5f},
					{"Rotation Amplitude", 150.0f},
					{"Easing Speed (0~1)", 0.05f},
					{"Scale", 1.0f},
					{"Opacity (0~1)", 0.9f},
					{"Fade In Time (ms)", 1200L},
					{"Fade Out Time (ms)", 5000L},
					{"Show Temporarily", true},
					{"Show Duration (ms)", 5000L},

					MAKE_COMBOBOX("Color", "White",
						{"Flow", NAMED_COLOR_BASE_LIST})
				}
			},

			{"Target HUD",
				{
					MAKE_COMBOBOX("Target", "Foreground",
						{"Foreground", "PointAt", "it (Pronoun)"}),

					{"Avatar Circle", true},
					{"Avatar Enabled", true},
					MAKE_COMBOBOX("Avatar Type", "Band",
						{"Process", "Random", "Band", "Custom"}),
					{"Avatar Custom Image", "steve.png"},
					{"Hide Process Ext", false},
					{"Show Title", true},
					{"Show Class Name", true},

					{"UWP Show Original Process", true},

					MAKE_COMBOBOX("HUD Position", "Follow",
						{"Follow", "Fixed"}),

					MAKE_COMBOBOX("HUD Background Color", "Flow",
						{"Transparent", "Flow", NAMED_COLOR_BASE_LIST}),

					{"HUD Background Darkness (0~1)", 0.85f},
					{"HUD Background Opacity (0~1)", 0.8f},
					{"HUD Round Corners", true},
					{"HUD Roundness", 0.6f},
					{"HUD Shadow", true},
					{"HUD Shadow Opacity (0~1)", 0.7f},
					{"HUD Shadow Thickness", 60.0f},

					{"Mouse Click Feedback", true},
					{"Mouse Click Feedback Particles", true},
					MAKE_COMBOBOX("Mouse Click Feedback Color", "Red",
						{"Dynamic", NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Process Name Color", "Flow",
						{"Flow", "Dynamic", NAMED_COLOR_BASE_LIST}),

					{"Health Bar", false},
					MAKE_COMBOBOX("Health Bar Style", "Rectangle",
						{"Rectangle", "Background"}),
					MAKE_COMBOBOX("Health Bar Direction", "Left",
						{"Left", "Right"}),

					{"Health Bar Rectangle Height", 8},
					{"Health Bar Rectangle Width", 260},
					{"Health Bar Expanded Width", false},
					{"Health Bar Vertical Gap", 25},
					{"Health Bar Bottom Margin", 20},
					{"Health Bar Rounded Corners", true},
					{"Health Bar Roundness", 0.4f},
					{"Health Bar Box", false},
					MAKE_COMBOBOX("Health Bar Box Color", "Gray",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Health Source", "CPU Usage",
						{"CPU Usage", "GPU Usage"}),
					{"Health Source Update Cooldown (ms)", 3000L},
					{"Health Source Use Integer", true},
					{"Health Source CPU Max", 20.0f},
					{"Health Source GPU Max", 100.0f},
					{"Health Source Reversed", true},
					{"Health Easing", true},
					{"Health Drop Feedback", true},
					{"Health Drop Feedback Particles", true},
					{"Health Show Max", true},
					{"Health Show Number", true},
					MAKE_COMBOBOX("Health Number Affix", "Off",
						{"Off", "Heart", "HP", "hp", "Prefix"}),
					MAKE_COMBOBOX("Health Number Position", "Follow",
						{"Up", "Right", "Follow"}),
					{"Health Number Mapping", true},
					{"Health Number Mapping Max", 20.0f},
					MAKE_COMBOBOX("Health Number Color", "White",
						{"Dynamic", NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Health Bar Color", "Dynamic",
						{"Dynamic", "Flow", NAMED_COLOR_BASE_LIST}),

					{"Show PID", true},
					{"Show Distance", false},
					MAKE_COMBOBOX("Distance Unit", "Off",
						{"Off", "m", "px"}),
					{"Distance Prefix", false},
					MAKE_COMBOBOX("Distance Position", "Middle",
						{"Right", "Middle"}),

					MAKE_COMBOBOX("HUD Shadow Color", "Black",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("HUD Outline Color", "Dark Green",
						{"Transparent", NAMED_COLOR_BASE_LIST}),

					{"Give Way to Mouse", true},

					{"Background Image", false},
					{"Background Image Path", ""},
					//{"Background Image Scale", 1.0f},
					{"Background Image Opacity (0~1)", 0.5f},
					{"Background Image Moving Speed", 0.5f},

					{"Fixed X Rate", 0.85f},
					{"Fixed Y Rate", 0.65f},

					{"Easing", true},
					{"Easing Speed (0~1)", 0.2f},
					{"Fade Time (ms)", 500L},
					MAKE_COMBOBOX("Animation", "Enlarge II",
						{"Off", "Expand", "Enlarge", "Enlarge II", "Shrink", "Shrink II"}),
					{"Animation Duration (ms)", 500L},

					MAKE_COMBOBOX("Style", "Custom",
						{"Custom", "Default", "Normal", "Rise", "Augustus", "Raven"}),

					MAKE_COMBOBOX("Command Line Getter", "Console Output",
						{"Off", "Console Output", "Copy"}),

					{"Command Line Getter Hotkey", {{"Keybind", {VK_LCONTROL, VK_LWIN, VK_SUBTRACT}}}},
				}
			},

			{"Anti Browser",
				{
					{"Async", true},

					MAKE_COMBOBOX("Filter", "OpenUrl Browser",
						{"Any Browser", "OpenUrl Browser", "OpenHttpUrl Browser",
						"OpenUrl Process", "OpenHttpUrl Process",
						}),

					MAKE_COMBOBOX("Measures", "Kill",
						{"Warn", "Kill", "SilentKill", "KillParent", "KillFamily"}),

					{"Check Cooldown", 1000U},
				}
			},

			{"IRC",
				{
					{"Realm WS Timeout (s)", 12},
					{"Realm Auto Resume", true},

					MAKE_COMBOBOX("Quick Send Style", "Input Box",
					{"Off", "Bottom Chat", "Input Box"}),

					{"Quick Send Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, '0'}}}},

					{"Fast Send With # Prefix Command", true},

					MAKE_COMBOBOX("Notify My Mentions", "Notify",
					{"Off", "Notify", "Chatter", "Title", "Actionbar", "WinToast"}),
					
					MAKE_COMBOBOX("Message Notify Type", "Notify",
					{"Off", "Notify", "Chatter", "Actionbar", "Title", "Island"}),
					{"Console Output", true},

					{"Speak Message", true},
					{"Speak Max Length", 60},

					{"Taboo Filter", false},

					{"Blocked User Names (Sep With Semicolon) (PRO)", ""},
					{"Underline Pro User Messages", true},

					{"Notify Log Messages", false},
					{"Debug Output", false},
					{"Ignore Old Messages", true},
					{"Old Messages Threshold (s)", 180},

					MAKE_COMBOBOX("Presence Tracking Mode", "Difference",
					{"Message", "Difference"}),
					{"Presence Poll Interval (s)", 30},
				}
			},

			{"IRC Legacy",
				{

					{"Async While Getting Username", true},

					{"Message Fetch Interval (ms)", 5000L},
					{"Message Fetch Timeout (s)", 20},
					{"Message Send Timeout (s)", 20},
					{"Presence Log Cooldown (s)", 300L},
					{"Exit Logout Via Loader", true},

					{"Old Messages Threshold (s)", 180},
					{"Ignore Old Messages", true},
					{"Cancel Sending When As Guest", true},
					{"Cancel Sending Repeated Message", true},
					{"Auto Change Name When Name Missing", true},

					MAKE_COMBOBOX("Notify My Mentions", "Notify",
					{"Off", "Notify", "Chatter", "Title", "Actionbar", "WinToast"}),
					
					MAKE_COMBOBOX("Message Notify Type", "Notify",
					{"Off", "Notify", "Chatter", "Actionbar", "Title", "Island"}),
					{"Notify Log Messages", false},

					MAKE_COMBOBOX("Text Database Update Method", "POST",
					{"Old", "GET", "POST"}),

					{"Message Length Limit Via GET", 39},

					{"Speak Message", true},
					{"Speak Max Length", 60},

					{"Console Output", true},
					{"Blocked User Names (Sep With Semicolon) (PRO)", ""},
					{"Underline Pro User Messages", true},

					{"Taboo Filter", false},
					{"Debug Output", false},
				}
			},

			{"Nick Generator",
				{
					MAKE_COMBOBOX("Mode", "NeteaseMC",
						{"English", "NeteaseMC", "Normal Random", "Japanese Random"}),
					{"Auto Copy", false},
					{"Count", 1},
				}
			},

			{"Anti Webpage",
				{
					{"Async", true},
					{"Only On Browser", true},

					{"Title Keywords 1 Enabled", true},
					{"Title Keywords 1", "传奇;一刀;贪玩;霸主;鬼服;福利;0氪;免费送;打金服;上线即领"},

					{"Title Keywords 2 Enabled", true},
					{"Title Keywords 2", "博彩;新澳;荷官;超高赔率"},

					{"Title Keywords 3 Enabled", true},
					{"Title Keywords 3", "page not found;404 not found;502 bad gateway"},

					{"Title Keywords Custom Enabled", false},
					{"Title Keywords Custom", ""},

					MAKE_COMBOBOX("Target Window", "Foreground",
						{"Foreground", "PointAt"}),

					MAKE_COMBOBOX("Notify Mode", "Notify",
						{"Off", "Notify", "Chatter"}),

					{"Chatter Color", "255;203;0;230"},

					MAKE_COMBOBOX("Operation", "Close Page",
						{"Off", "Close Page", "Close Window"}),

					{"Ctrl+W Internal Delay (ms)", 100},

					/*MAKE_COMBOBOX("Mute Mode", "System - Auto Toggle",
						{"System - Direct", "System - Enable Mute Module", "System - Auto Toggle",
						 "Browser - Direct", "Browser - Auto Toggle",
							}),*/

					{"Check Cooldown", 500U},
				}
			},

			{"Live Chatter",
				{
					MAKE_COMBOBOX("Auto Send Time Mode", "Off",
						{"Off", "Periodic"}),

					{"Auto Send Periodic Interval (ms)", 60000L},
					
					MAKE_COMBOBOX("Auto Send Content Mode", "Fixed",
						{"Fixed", "List Random Element", "List Loop", "Prefab", "File Lines"}),

					MAKE_COMBOBOX("Auto Send Prefab Type", "Aphorism",
						{"Aphorism", "Idiom Solitaire", "Ask Solitaire"}),

					{"Auto Send Fixed Content", "给主播点个关注~"},
					{"Auto Send List Content (Sep With Semicolon)", ""},
					{"Auto Send List Current Index", 0},
					{"Auto Send File Source Path", ""},

					MAKE_COMBOBOX("Clipboard Quick Send", "Off",
						{"Off", "Send", "Copy and Send", "Select All, Copy and Send"}),

					{"Clipboard Quick Send Key", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_ADD}}}},

					{"Clipboard Quick Send Confirm", false},
					{"Clipboard Quick Send Confirm Time (s)", 5},
					{"Clipboard Quick Send Prevent Repeat", true},
					{"Clipboard Quick Send Apply Text Processor", false},

					{"Auto Send Split Cooldown Min (ms)", 1000},
					{"Auto Send Split Cooldown Max (ms)", 2000},
					{"Send Cooldown (ms)", 2000L},
					{"Prevent Others Room Chatter Sending", true},

					{"Max Allowed Chatter Delay (s)", 60U},
					{"Single Chatter Length Limit", 40U},

					MAKE_COMBOBOX("Color", "White",
						{"White", NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Display", "Chatter",
						{"Off", "Chatter", "Notify", "Title", "Actionbar"}),

#ifdef PROFESSIONAL_VERSION
					MAKE_COMBOBOX("User Filter (PRO)", "All",
						{"All", "Fans", "Paid Fans", "Guard"}),
#else
					MAKE_COMBOBOX("User Filter (PRO)", "All",
						{"All"}),
#endif

					MAKE_COMBOBOX("User Name Display", "Default",
						{"Default", "Head", "Head + Tail", "UID", "Netease Nickname"}),

					{"Horizontal Reverse", false},

					MAKE_COMBOBOX("Actionbar Color", "Colorful",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Title Color", "White",
						{"Flow", NAMED_COLOR_BASE_LIST}),

					{"Title Font Size", 150},

					{"Console Output", true},
					{"Console Output Timestamp", true},
					{"Console Output Wealth & Medal", true},

					{"File Output", false},
					{"File Output Format", "{{content}}`{{nickname}}"},
					{"File Output Path", "output\\Chatters.txt"},

					{"User Whitelist Enabled", false},
					{"User Whitelist (Sep With Semicolon)", "Wormwaker;Worrnwaker"},
					{"User Blacklist Enabled", false},
					{"User Blacklist (Sep With Semicolon)", ""},

					{"Custom Filter Enabled", false},
					{"Custom Filter Keywords (Sep With Semicolon)", ""},

					MAKE_COMBOBOX("Taboo Filter", "Replace (Unsafe)",
						{"Off", "Block", "Filtered", "Replace (Unsafe)"}),

					MAKE_COMBOBOX("Remote Execution (Riskful)", "Disabled",
						{"Disabled", "Wormwake"}),

					{"Remote Execution Username Whitelist (Sep with Semicolon)", "Wormwaker;Worrnwaker"},
					
					MAKE_COMBOBOX("Remote Execution Privileges Policy", "Admin & Normal",
					{"Everyone Admin", "Admin & Normal", "Only Admin", "Everyone Normal"}),

					{"Remote Execution Display", false},
					{"Remote Execution Notify", true},

					MAKE_COMBOBOX("Speaker", "Off",
						{"Off", "Username & Text", "Only Text"}),

					{"Speaker User Whitelist Enabled", false},
					{"Speaker User Whitelist (Sep With Semicolon)", "Wormwaker;Worrnwaker"},
					{"Speaker User Blacklist Enabled", false},
					{"Speaker User Blacklist (Sep With Semicolon)", ""},

					MAKE_COMBOBOX("Translator", "Off",
						{"Off", "Chinese", "English", "Exchange"}),

					{"Speaker Skip Emoji", true},
					{"Speaker Async", true},

					MAKE_SOUNDITEM("Sound", "Off"),

					{"Triggers Enabled", false},
					{"Trigger Disable Speaker", true},
					{"Triggers Using Regex", true},
					{"Triggers Config Path", "config\\liveStreamChatterTriggers.ini"},

					MAKE_COMBOBOX("Transform Emoji", "Character",
						{"Off", "Character", "Braces"}),

					MAKE_COMBOBOX("AI Response", "Off",
					{"Off", "Notify", "Speak", "Chatter", "Title", "Actionbar", "Real Chatter"}),

					MAKE_COMBOBOX("AI Response Chatter Type", "Top",
					{"Scroll", "Top", "Bottom", "Reverse", "Horizontal", "Vertical", "Random"}),

					MAKE_COMBOBOX("AI Response Chatter Color", "Red",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("AI Response Title Color", "Red",
						{NAMED_COLOR_BASE_LIST}),

					{"AI Response Prefix", true},
					{"AI Response Prefix String", "回复@{user}:"},
					{"AI Response Prompt", "请用简要的语言回复这条直播间弹幕，最好不要超过20字，但是不要复述弹幕："},
					{"AI Response Prompt (With Contexts)", "请用简要的语言和直播间弹幕进行对话，每次你的输出一定不要超过40字，不要思考过程，不要复述用户的消息。下面开始对话。"},
					{"AI Response Cooldown (ms)", 5000L},
					{"AI Response Contexts Enabled", true},
					{"AI Response Contexts Limit", 64},
					{"AI Response User Blacklist Enabled", true},
					{"AI Response User Blacklist (Sep With Semicolon)", "Wormwaker;Worrnwaker"},
				}
			},

			{"Tcp Monitor",
				{
					{"Check Cooldown (ms)", 1000L},

					{"Filter Processes", true},
					{"Process Name Whitelist (Empty For Any)", ""},
					{"Process Name Blacklist (Empty For Disabled)", "JackalClient.exe"},
					{"Process Id Whitelist (Zero For Any)", "0"},
					{"Process Id Blacklist (Zero For Disabled)", "0"},

					MAKE_COMBOBOX("Notify Mode", "Chatter",
					 {"Notify", "Chatter", "Actionbar"}),

					MAKE_COMBOBOX("Chatter Color (New Connection)", "Gold",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Chatter Color (Closed Connection)", "Purple",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Chatter Type", "Random",
					{"Scroll", "Top", "Bottom", "Reverse", "Horizontal", "Vertical", "Random"}),	// 弹幕类型

					{"Filter Ports", false},
					{"Ports Whitelist (e.g. 4-10,80)", "80,443"},
					{"Ports Blacklist (e.g. 4-10,80)", ""},
					MAKE_COMBOBOX("Port Type", "Remote",
						{"Remote", "Local"}),

					{"Filter IPs", false},
					{"Exclude LAN IP", true},
					{"IP Whitelist (Sep With Semicolon)", ""},
					{"IP Blacklist (Sep With Semicolon)", ""},
					MAKE_COMBOBOX("IP Type", "Remote",
						{"Remote", "Local"}),

					{"Show IP Addresses", true},
					{"Query External IP Position", false},
				}
			},

			{"Tcp Killer",
				{
					MAKE_COMBOBOX("Mode", "Once", {"Once", "Keep"}),

					{"Keep Mode Cooldown (ms)", 200U},

					{"Filter Processes", false},
					{"Process Name (Empty For Any)", ""},
					{"Process Id (Zero For Any)", 0},
					{"Max Disconnection Count", 65535},

					MAKE_COMBOBOX("Notify", "Smart",
					 {"Off", "Only Error", "Smart", "All"}),

					MAKE_COMBOBOX("Notify Mode", "Notify",
					 {"Notify", "Chatter", "Actionbar"}),

					{"Filter Ports", true},
					{"Ports Whitelist (e.g. 4-10,80)", "80,443"},
					{"Ports Blacklist (e.g. 4-10,80)", ""},
					MAKE_COMBOBOX("Port Type", "Remote",
						{"Remote", "Local"}),

					{"Filter IPs", false},
					{"Exclude LAN IP", true},
					{"IP Whitelist (Sep With Semicolon)", ""},
					{"IP Blacklist (Sep With Semicolon)", ""},
					MAKE_COMBOBOX("IP Type", "Remote",
						{"Remote", "Local"}),
				}
			},

			{"Anti 360Ad",
				{
					{"Kill 360 Ad Processes", true},
					{"Remove 360 Suspended Ball", true},

					{"MultiTip.exe", true},
					{"sesvcr.exe", true},
					{"360SpeedldHealth.exe", true},

				}
			},

				{"Anti Popups",
					{
						MAKE_COMBOBOX("Ad Process Policy", "Warn & AutoKill",
							{"Ignore", "Warn", "AutoKill", "Warn & AutoKill"}),

							/*MAKE_COMBOBOX("Confirm", "Off",
								{"Off", "HUD", "HUDTimeout", "Msgbox", "MsgboxTimeout", }),*/

						MAKE_COMBOBOX("BottomRight Judge Policy", "Size or Blacklist",
							{
								"Size",
								"Title",
								"Size and Title",
								"Size or Blacklist",
								"Title or Blacklist",
								"Size and Title or Blacklist",
							}),

						MAKE_COMBOBOX("Others Judge Policy", "Title or Blacklist",
							{
								"Title",
								"Blacklist",
								"Title or Blacklist",
							}),

						MAKE_COMBOBOX("Measures", "Chain",
							{"Chain", "Close", "Destroy", "EndSession", "KillProcess"}
							),

						{"Ad Window Title Keywords List", "每日;开通会员;游戏中心;今日;新闻;优选;精选;推荐;热搜;软件管家;贴士;小助手;奖励;特惠;公测;一刀;贪玩;上线;News;Free Trial"},
						{"Chain Allow LegitMouseClick", true},
						{"Chain LegitMouseClick Internal Delay (ms)", 200},
						{"Chain LegitMouseClick X Margin Min", 14},
						{"Chain LegitMouseClick X Margin Max", 22},
						{"Chain LegitMouseClick Y Margin Min", 14},
						{"Chain LegitMouseClick Y Margin Max", 22},
						{"Chain Allow Move Window Out", true},
						{"Check Cooldown", 250U},
						{"Exclude Maximized", false},
						{"Exclude MessageBox", true},
						{"Exclude SystemProcess", true},
						{"Exclude WinToast", true},

						{"Blacklist Processes (Sep With Semicolon)", "mini.lohaslady.exe;FlashHelperService.exe;MultiTip.exe;sesvcr.exe;360SpeedldHealth.exe;360SpeedIdHealth.exe;360SpeedIdHealthEx.exe;Tgmn.exe;Tnuser.exe;Svnpnd.exe;SGNews.exe;biz_helper.exe;SOGOUSmartAssistant.exe;DesktopAssistant.exe;LenovoAppStore.exe;aipiclaunch.exe;SoftMgr.exe;NewIdView.exe;SodaDownloader.exe"},
						{"Whitelist Processes Enabled", true},
						{"Whitelist Processes (Sep With Semicolon)", "哔哩哔哩.exe;QQ.exe;explorer.exe;Snipaste.exe;steam.exe;steamwebhelper.exe;msedge.exe;iexplore.exe;firefox.exe"},
					}
				},

{"Anti Topmost",
	{
		{"Only Check Foreground", false},
		{"Auto Untopmost", true},
		{"Auto Bottom", true},

		MAKE_COMBOBOX("Violence Policy", "Off",
			{"Off", "Close Window", "Kill Process"}
		),

		{"Notify Kill", true},

/*{"Violence Policy",
{
{"Options", {"Off", "Close Window", "Kill Process"}},
{"Selected", "Off"}
}
},*/

/*	{"Auto Kill", false},
{"Kill Process Instead of Window", true},*/
	}
},

{"Hide Taskbar",
	{
		{"Notify", false},
	}
},

{"Auto Translate",
	{
		{"Async", true},

		MAKE_COMBOBOX("Target", "Foreground",
			{"Screen", "Foreground", "PointAt"}),

		{"Screen Mode Exclude Client", true},

		MAKE_COMBOBOX("Action", "Translate",
			{"Translate", "Recognize"}),

		MAKE_COMBOBOX("Source Language", "English",
			{/*"Non-chinese", */"English", "Chinese"}),

		MAKE_COMBOBOX("Text Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Text Color (Pointed At)", "Green",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Translation Result Color", "Yellow",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Text Background Color", "Red",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Text Background Color (Pointed At)", "Dark Green",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Translation Result Background Color", "Black",
			{NAMED_COLOR_BASE_LIST}),

		{"Translation Max Thread Count", 20},

		MAKE_COMBOBOX("Texts Pointed At", "Raw",
			{"Hidden", "Raw", "Result"}),

		{"Show Texts", true},
		{"Text Background", true},
		{"Text Background Opacity (0~1)", 0.5f},
		{"Text Background Opacity (Mouse Pointed At) (0~1)", 0.5f},
		{"Text Min Size", 20},
		{"Text Max Size", 80},
		{"Translation Result Min Size", 30},
		{"Translation Result Max Size", 100},
		{"Text Opacity (0~1)", 0.8f},

		{"Recognize Min Confidence (0~100)", 80.0f},

		/*MAKE_COMBOBOX("Dest Language", "Chinese",
			{"Chinese", "English"}),*/

		MAKE_COMBOBOX("Trigger Mode", "Manual",
			{"Periodic", "On Window Change", "Manual"}),

		{"Merge Texts Into Groups", true},
		{"Merge Texts Vertical Gap Threshold", 0.5f},
		{"Merge Texts Horizontal Gap Threshold", 3.0f},

		{"Recognize Cooldown (ms)", 3000L},
		{"Toggle Texts Hotkey", {{"Keybind", {0}}}},
		{"Trigger Hotkey", {{"Keybind", {0}}}},
		{"Re-merge Texts Hotkey", {{"Keybind", {0}}}},
		{"Clear Hotkey", {{"Keybind", {VK_CAPITAL}}}},
	}
},

{"Auto Focus",
	{
		MAKE_COMBOBOX("Mode", "PointAt",
			{"PointAt", "Foreground Locked"}),

		MAKE_COMBOBOX("Notify", "Off",
			{"Off", "Notify", "Chatter", "Actionbar"}),

		{"Disable When Menu On", false},
		{"Disable When Quit", false},
		{"Check Cooldown (ms)", 200},
		{"Restore Window While Focusing", false},
	}
},

{"Hover Focus",
	{
		{"Hover Timeout (ms)", 1000L},
		{"Bring to Top", false},
	}
},

{"Close Enhance",
	{
		MAKE_COMBOBOX("Method", "EndSession",
			{"EndSession", "KillProcess", "EndTask"}),

		{"Exclude Self", true},
	}
},

{"Dialog Physics",
	{
		MAKE_COMBOBOX("Constant Mode", "Float",
			{"Off", "Fall", "Bounce", "Float"}),

		/*MAKE_COMBOBOX("Start Position", "Off",
			{"Off", "Random", "Up", "Down", "Left", "Right"}),*/

		MAKE_COMBOBOX("Collision", "Omnidirectional",
			{"Off", "Orthogonal", "Omnidirectional"}),

		{"Gravity", 9.8f},
		{"Basic Friction", 0.03f},
		{"Step", 0.1f},
		{"Dialog Bounce Damping", 0.6f},

		{"Pause When Menu On", true},

		{"Drag Inertia", 20.0f},
		{"Drag Spring K", 20.0f},
		{"Drag Damping", 3.0f},

		{"Initial Velocity", false},
		{"Initial Min Velocity", 4.0f},
		{"Initial Max Velocity", 8.0f},
		{"Initial Random Degree", true},
		{"Initial Custom Degree", 1.57f},
	}
},

	{"Tasklist",
		{
			{"Async", true},
			{"Auto Console", true},
			{"Use Record", false},

			{"Verify Signature", false},

			MAKE_COMBOBOX("Style", "Normal",
				 {"Vanilla", "Normal", "Pathes", "Command Lines"})

				 /*{"Style",
					 {
						 {"Options", {"Vanilla", "Normal", "Command Lines"}},
						 {"Selected", "Normal"}
					 }
				 }*/
				 /*{"Use Vanilla", false},
				 {"Display Command Line", true},*/
		 }
	 },

	 {"List Modules",
		 {
			 {"Async", true},
			 {"Auto Console", true},
			 {"PID (0 for self)", 0},
			 {"Verify", true},
		 }
	 },

	 { "List Trays",
		 {
			 {"Async", true},
			 {"Auto Console", true},
		 }
	 },

	 {"List Services",
		 {
			 {"Async", true},
			 {"Auto Console", true},
			 MAKE_COMBOBOX("Style", "Normal",
			 {"Vanilla", "Vanilla (Only Win32)", "Vanilla (Only Drivers)", "Vanilla Custom", "Normal", "Simple"}),
			 {"Vanilla Enum Custom Command", "sc query" },
		 }
	 },

	 {"List Tasks",
		{
			{"Async", true},
			{"Auto Console", true},

			MAKE_COMBOBOX("Style", "Normal",
				{"Normal", "Vanilla (List)", "Vanilla (XML)", "Vanilla (CSV)"}),
		}
	},

	 { "List Drivers",
		 {
			 {"Async", true},
			 {"Auto Console", true},
			 {"Verify", true},
		 }
	 },

	 {"Elevator",
		 {
			 {"Process Name (Empty For Any)", "JackalClient.exe"},
			 {"Process Id (Zero For Any)", 0},
			 {"Max Process Count", 8},
		 }
	 },

	 {"Force Terminator",
		 {
			 MAKE_COMBOBOX("Mode", "Process",
				 {"Process", "Thread", "Memory"}),
			 {"Async", true},
			 {"Close Menu", false},
			 {"Confirm Before Termination", false},
			 {"Process Name (Empty For Any)", "JackalClient.exe"},
			 {"Process Id (Zero For Any)", 0},
			 {"Max Process Count", 8},
		 }
	 },

	 {"Injector",
		 {
			 MAKE_COMBOBOX("Method", "NtCreateThreadEx",
				 {
					 "CreateRemoteThread",
					 "NtCreateThreadEx",
					 "QueueUserAPC",
					 "Reflective",
					 "Reflective (External)",
				 }),

			 MAKE_COMBOBOX("Execution Policy", "Async",
				 {"Sync", "Async", "Async NoWait"}),

			 MAKE_COMBOBOX("Operation", "InjectDll",
					 {"InjectDll", "UninjectDll"}),

			 MAKE_COMBOBOX("Process Architecture", "Both",
				 {"Both", "x64", "x86"}),

			 {"Exclude Self", true},
			 {"Process Name (Empty For Any)", "cmd.exe"},
			 {"Process Id (Zero For Any)", 0},
			 {"Dll Path", ""},
			 {"Max Process Count", 8},
		 }
	 },

	 {"Remote Run",
		 {
			 MAKE_COMBOBOX("Execution Policy", "Async",
				 {"Sync", "Async", "Async NoWait"}),

			 MAKE_COMBOBOX("Process Architecture", "Both",
				 {"Both", "x64", "x86"}),

			 MAKE_COMBOBOX("Injection Architecture", "Auto",
				 {"Auto", "x64", "x86"}),

			 {"Exclude Self", true},
			 {"Process Name (Empty For Any)", "cmd.exe"},
			 {"Process Id (Zero For Any)", 0},
			 {"Command Line", "cmd.exe /c echo Jackal On Crack! && pause"},
			 {"Max Process Count", 8},
		 }
	 },


	 {"Speedhack",
		 {
			 {"Process Name (Empty For Any)", "javaw.exe"},
			 {"Process Id (Zero For Any)", 0},
			 {"Speed", 0.5f},
			 {"Anti Unload", false},
			 { "Speed Change Step", 0.1f},
			 { "Speed Up Keybind", {{"Keybind", {VK_RMENU, 187}}} },		// RAlt + =
			 { "Speed Down Keybind", {{"Keybind", {VK_RMENU, 189}}} },	// RAlt + -
			 /*{" Pause/Resume Keybind",},*/
		 }
	 },

	 {"Genshin Impact",
		 {
			 MAKE_COMBOBOX("Enable Action",
				 "Install & Start",
				 {"Fake", "Start", "Install & Start"}
				 ),

			 {"Auto Boot", false},	// 开机启动原神
			 {"Boot Sound", true},	// 是否开启专属启动音效

			 MAKE_COMBOBOX("Disable Action",
				 "Kill Process",
			 {"Close Window", "Kill Process", "Close Window & Uninstall", "Kill Process & Uninstall"}
			 )
		 }
	 },

	 {"Window Tags",
		 {
			 {"Easing", true},
			 {"Easing Speed (0~1)", 0.2f},

			 /*MAKE_COMBOBOX("Style", "Simple",
				 {"Simple", ""}),*/

			 //{"Aim Foreground Window Only", false},

			 MAKE_COMBOBOX("Target", "PointAt",
				{"PointAt", "Foreground"}),

			 {"Aura Target Highlight", true},
			 {"Give Way to Mouse", true},
			 {"Show Handle Value", true},
			 {"Show Process Info", true},
			 {"Show Parent Info", true},
			 {"Show Position", false},
			 {"Show Z-Order Band", false},
			 {"Show Size", false},
			 {"Special Z-Order Anti-Obstruction", true},
			 {"Font Size", 18},
			 {"Text Background", true},
			 {"Opacity Min (0~1)", 0.75f},
			 {"Opacity Max (0~1)", 0.9f},
			 {"Hide When Menu On", true},
		 }
	 },

	 {"Max Aura",
		 {
			 {"Cooldown (ms)", 400U},
		 }
	 },

	 { "Min Aura",
		 {
			 {"Cooldown (ms)", 400U},

		 }
	 },

	 { "Freeze Aura",
		 {
			 {"Cooldown (ms)", 400U},
		 }
	 },

	 { "Uncross Aura",
		 {
			 {"Cooldown (ms)", 400U},
		 }
	 },

	 { "Ruin Aura",
		 {
			 {"Cooldown (ms)", 400U},
		 }
	 },

	 {"Aim Assist",
		 {
			 {"Smoothness", 0.8f},
		 }
	 },

	 {"Kill Aura Legit",
		 {
			 {"Smoothness", 0.8f}
		 }
	 },

	 {"Trigger Bot",
		 {
			 {"Cooldown (ms)", 400U},
			 {"Notify", true}
		 }
	 },

	 {"Ruler",
		 {
			 MAKE_COMBOBOX("Line Color", "Red",
				 {NAMED_COLOR_BASE_LIST}),

			 {"Line Width", 2},
			 {"Info Font Size", 20},
			 {"Show Size", true},
			 {"Mark Sides", true},
			 {"Measure Distances", true},
			 {"Hide When Menu On", true},
		 }
	 },

	 {"Debug ESP",
		{
			{"Capture Win32", true},
			{"Capture Global Win32 (Admin Required)", false},

			MAKE_COMBOBOX("Display Mode", "Chatter",
				{"Console Output", "Chatter", "Notify", "Title", "Actionbar", "Speak"}),

			MAKE_COMBOBOX("Show Process Source", "Both",
			{"Off", "PID", "Process Name", "Both"}),

			{"Show Namespace Source", false},
			{"Anti Spam", true},

			MAKE_COMBOBOX("Chatter Type", "Top",
			{"Scroll", "Top", "Bottom", "Reverse", "Horizontal", "Vertical", "Random"}),	// 弹幕类型
		}
	},

	 {"Process ESP",
		{
			MAKE_COMBOBOX("New Process Notify Mode",
				"Notify",
				{"Off", "Notify", "Chatter", "Title"}),

			MAKE_COMBOBOX("Exited Process Notify Mode",
				"Notify",
				{"Off", "Notify", "Chatter", "Title"}),

			{"New Process Parent Display", true},
			{"New Process Notify Blacklist Enabled", false},
			{"New Process Notify Blacklist (Regex Sep With Semicolon)", "loader\\.exe;conhost\\.exe;tesseract\\.exe"},
			{"New Process Notify Whitelist Enabled", false},
			{"New Process Notify Whitelist (Regex Sep With Semicolon)", "cmd\\.exe;explorer\\.exe;Hips[a-zA-Z]+\\.exe;360[a-zA-Z0-9]+\\.exe"},

			//{"Exited Process Parent Display", true},
			{"Exited Process Notify Blacklist Enabled", false},
			{"Exited Process Notify Blacklist (Regex Sep With Semicolon)", "loader\\.exe;conhost\\.exe;tesseract\\.exe"},
			{"Exited Process Notify Whitelist Enabled", false},
			{"Exited Process Notify Whitelist (Regex Sep With Semicolon)", "cmd\\.exe;explorer\\.exe;Hips[a-zA-Z]+\\.exe;360[a-zA-Z0-9]+\\.exe"},

			{"Check Cooldown (ms)", 100L},
		}
	 },

	 {"Compile ESP",
		{
			MAKE_COMBOBOX("Compile Start Notify Mode",
				"Notify",
				{"Off", "Notify", "Chatter", "Title", "Island", "Console Output", "WinToast", "Speak", "Real Chatter"}),

			MAKE_COMBOBOX("Compile Finish Notify Mode",
				"Notify",
				{"Off", "Notify", "Chatter", "Title", "Island", "Console Output", "WinToast", "Speak", "Real Chatter"}),

			{"Show PID", true},
			{"Show Command Line", false},
			{"Show Duration", true},
			MAKE_COMBOBOX("Arraylist Extra Info", "Type",
				{"Off", "Type", "Tool", "Target File", "Type + File"}),
			{"HUD", true},
			{"Hide HUD When Menu On", false},
			{"HUD Main Text", "Compiling..."},
			MAKE_COMBOBOX("HUD Subtext", "Type + Duration",
				{"Off", "Type", "Tool", "Duration", "Type + Duration", "Type + Tool + Duration"}),
			{"HUD Show Task Count", true},
			{"HUD X Rate", 0.5f},
			{"HUD Y Rate", 0.56f},
			{"HUD Text Font Size", 24},
			{"HUD Text Gap", 8},
			{"HUD Text Line Gap", 3},
			{"HUD Padding", 14},
			{"HUD Extra Height", 12},
			{"HUD Opacity (0~1)", 0.92f},
			MAKE_COMBOBOX("HUD Text Color", "White",
				{"Flow", NAMED_COLOR_BASE_LIST}),
			MAKE_COMBOBOX("HUD Subtext Color", "Aqua",
				{"Flow", NAMED_COLOR_BASE_LIST}),
			{"HUD Background", true},
			MAKE_COMBOBOX("HUD Background Color", "Black",
				{"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),
			{"HUD Background Opacity (0~1)", 0.35f},
			{"HUD Background Roundness", 0.3f},
			{"HUD Loading Radius", 18.0f},
			{"HUD Loading Thickness", 5.0f},
			{"HUD Loading Period (ms)", 1800L},
			MAKE_COMBOBOX("HUD Loading Color 1", "Aqua",
				{"Flow", NAMED_COLOR_BASE_LIST}),
			MAKE_COMBOBOX("HUD Loading Color 2", "Sky Blue",
				{"Flow", NAMED_COLOR_BASE_LIST}),
			{"HUD Fade In Duration (ms)", 2000L},
			{"HUD Fade Out Duration (ms)", 1000L},

			{"Compiler Process Blacklist Enabled", false},
			{"Compiler Process Blacklist (Regex Sep With Semicolon)", ""},
			{"Compiler Process Whitelist (Regex Sep With Semicolon)", ""},

			{"Check Cooldown (ms)", 300L},
		}
	 },

	 {"Process Kill",
		 {

			 MAKE_COMBOBOX("Method", "Chain",
				 {"Chain", "Normal", "Thread Killer", "Thread Patcher", "Winsta", "Debugger", "Job", "WMI", "Kernel"}),

			 {"Kill Names (Sep with Semicolon)", "dwm.exe"},
			 {"Kill PID",  0},
			 {"Notify Kill", true},
			 {"Disable After Attempt", true},
			 {"Keep", false},
		 }
	 },

	 {"Process Freeze",
		 {
			 {"Freeze Name", "1.exe"},
			 {"Freeze PID",  0},
			 {"Notify Freeze", true},
			 {"Disable After Attempt", false},
			 {"Keep", true},
		 }
	 },

	 { "Regedit",
		 {
			 {"No Wow64 Redirection", true},
		 }
	  },

	 {"Run",
		 {
			 {"Target", "cmd.exe"},
			 {"Parameters", ""},
			 {"Directory", ""},
			 {"Hidden", false},
			 {"Watch", false},
		 }
	 },

	 {"Quick Run",
		{
			MAKE_COMBOBOX("Execution", "system & pause",
				{"ShellExecute", "system", "system & pause"}),

			MAKE_COMBOBOX("Unknown Command Auto Resolve", "Confirm",
				{"Off", "Confirm", "Run"}),
			{"Remember Multi-Result Selection", true},

			{"Scan Skip Readonly Files", false},
			{"Scan Skip Hidden Files", false},
			{"Scan Skip System Files", false},

			{"Confirm Before Scanning", true},

			{"Output While Scanning", true},
			{"Output Error", false},

			 MAKE_COMBOBOX("Scan Policy", "Lazy",
				 {"Lazy", "Launch", "Daily"}),

			 //{"SAVED PROGRAMS", ""},
			 
		}
	 },

	 {"Open URL",
		 {
			 {"URL", "https://space.bilibili.com/3494361276877525"},
		 }
	 },

	 {"Cmd",
		 {
			 {"Run As Admin", false},
			 {"No Wow64 Redirection", true},
		 }
	 },

	 {"Super Cmd",
		{
			MAKE_COMBOBOX("Mode", "System",
				{"Admin", "Admin UAC Bypass", "System", "Trusted Installer"}),

			{"SetPrivileges Waiting Start Timeout (ms)", 5000L},
			{"Enable Privileges", true},
			{"No Wow64 Redirection", true},
		}
	 },

	 {"PowerShell",
		 {
			 {"Run As Admin", false},
			 {"No Wow64 Redirection", true},
		 }
	 },

	 {"Perfmon",
		 {
			 {"Parameters", "/reS"},
			 {"No Wow64 Redirection", true},
		 }
	 },

	 {"Taskmgr",
		 {
			 {"No Wow64 Redirection", true}
		 }
	 },

	 {"PPL Butcher",
		 {
			 {"Only Kill Invalid", false},
		 }
	 },

	 {"File Delete",
		 {
			 {"Path", "null"},
			 {"Keep", false},
			 {"Notify", true},
			 MAKE_COMBOBOX("Mode", "Normal",
				 {"Normal", "Command", "Supreme"})
		 }
	 },

	 { "File Create",
		 {
			 {"Path", ""},
			 {"Keep", false},
			 {"Notify", true},
			 {"UNC Path", true},
			 {"Create Folder", false},
			 {"Readonly", false},
			 {"Hidden", false},
			 {"System", false}
		 }
	 },

	 { "File Monitor",
		 {
			 {"Folder", "D:\\"},
			 //{"Filter", "*.*"},
			 {"Console Output", true},
			 {"Log (Client)", false},
			 {"Log (Seperate)", false},
			 {"Notify", false},
			 {"Follow File Manager Tab", true},
			 MAKE_COMBOBOX("File Manager Highlight", "Background",
				 {"Off", "Background", "Underline"}),
			 {"Highlight Duration (ms)", 10000L},
			 {"Highlight Subfolder Changes", true},
			 {"Monitor Create", true},
			 {"Monitor Delete", true},
			 {"Monitor Modify", true},
			 {"Monitor Rename", true},
			 {"Exclude Client Files", true},
			 {"Exclude Recent", true},
			 {"Exclude Prefetch", true},
			 {"Ext Blacklist", ".log;.pf;.tmp;.db;.qqxlog;.db-wal;.lck"},
			 {"Cooldown", 100U},
		 }
	 },

	 { "Folder Clear",
		 {
			 {"Async", true},
			 {"Keep", false},
			 {"Confirm Once", true},
			 {"Path", "null"},
			 {"Filter", "*.*"},
			 {"Notify Errors", true},
			 {"Notify Result", true},
		 }
	 },

	 {"Temp Clear",
		 {
			 {"Async", true},
			 {"Keep", false},
			 {"Filter", "*.*"},
			 {"Notify Errors", true},
			 {"Notify Result", true},
		 }
	 },

	 {"Long Path",
		 {
			 {"Notify Restart Required", true},
		 }
	 },

	 {"Top Files",
		 {
			 {"Limit", 25U},
			 {"Directory", ""},
			 {"Async", true},
			 {"Auto Console", true},
		 }
	 },

	 {"Rubbish Clean",
		 {
			 {"Async", true},
			 {"Auto Console", true},
		 }
	 },

	 {"Recycler Clear",
		 {
			 {"Async", true},
			 {"Sound", true},
			 {"Confirm", true},
			 {"Progress Bar", true},
		 }
	 },

	 {"File Manager",
		{
			{"Async File Enum", true},

			MAKE_COMBOBOX("Icon Style", "Character",
				{"Off", "Character", "Normal", "Full"}),

			MAKE_COMBOBOX("File Operation API", "COM",
				{"COM", "Win32"}),

			MAKE_COMBOBOX("Multiple File Open", "Allow",
				{"Off", "Allow"}),

			{"Info Font Size", 30},
			{"File Enum Min Cooldown (ms)", 500L},
			{"File Enum Max Cooldown (ms)", 10000L},
			{"Slow File Enum Item Size Threshold", 50},
			{"Stop File Enum Item Size Threshold", 200},
			{"File Attributes Update Cooldown (ms)", 1000L},
			{"Directory Status Update Cooldown (ms)", 3000L},
			{"File Item Font Size", 35},
			{"File Item Line Gap", 5},
			{"Move Selection Cooldown (ms)", 100L},
			{"Wheel Sensitivity", 200.0f},
			{"Sort Files", true},
			{"File Filter", "*.*"},

#ifdef PROFESSIONAL_VERSION
			MAKE_COMBOBOX("File Time Colorful Highlight (PRO)", "Modified Time",
			{"Off", "Modified Time"}),
#else
			MAKE_COMBOBOX("File Time Colorful Highlight (PRO)", "Off",
			{"Off", "Modified Time"}),
#endif

			{"Check Directory Is Empty", true},

			{"Show Hidden Files", true},
			{"Show System Files", true},
			{"Show Modified Time", true},
			{"Show Attributes", true},
			{"Show File Size", true},
			{"Open Selected With Single Click", true},
#ifdef PROFESSIONAL_VERSION
			{"Show File Time Difference (PRO)", true},
#else
			{"Show File Time Difference (PRO)", false},
#endif

			//{"Clear Selected Before Using Shift", true},

			{"Drive Enum Cooldown (ms)", 1000L},
			{"Drive Enum Larger Cooldown (ms)", 3000L},
			{"Drive Icon Size", 50},
			{"Drive Font Size", 30},

			MAKE_COMBOBOX("Drive Space Bar Style", "Classic",
				{"Classic", "Absolute"}),

			MAKE_COMBOBOX("Drive Space Text Format", "Free / Total",
				{"Free / Total", "Used / Total"}),

			{"Drive Space Bar Absolute Coefficient (px/GB)", 1.1f},
			{"Drive Space Bar Width", 300},
			{"Drive Space Bar Height", 25},
			{"Drive Space Bar Color Start", "86;156;214;220"},
			{"Drive Space Bar Color End", "255;0;0;220"},
			{"Drive Show Serial Number", true},
			{"Drive Show Volume Label", true},
			{"Drive Show File System", true},

			{"Calc Selected Total Size", true},

			//{"Calc Selected Folder Total Size", true},
			MAKE_COMBOBOX("Calc Selected Folder Size", "Off",
				{"Off", "Async", "Sync"}),

			/*MAKE_COMBOBOX("Calc File Size Execution Policy", "Sync",
				{"Sync", "Async"}),*/
			
			MAKE_COMBOBOX("Deletion Confirmation", "Always",
				{"Off", "Only Force", "Always"}),

			MAKE_COMBOBOX("Sort By", "Name",
				{"Name", "Type", "Size", "Modified Time"}),

			MAKE_COMBOBOX("Sort Order", "Ascending",
				{"Ascending", "Descending"}),

			MAKE_COMBOBOX("UAC Bypass Method", "Computerdefaults Legit",
						{"Computerdefaults",
						"Computerdefaults Legit",
						"Fodhelper",
						"Fodhelper Legit",
						"Cmstp",
						"PCA (PRO)",
						"Sdclt",
						"Sdclt Legit",
						"Slui",
						"Slui Legit",
						}),

			{"Selected Item Background Color", "66;90;123;200"},
			{"Hovered Item Background Color", "137;104;205;90"},
			{"Selected Item Outline Color", "18;74;143;200"},
			{"Hovered Item Outline Color", "151;4;148;200"},

			{"Menu Outline Color", "255;185;15;255"},
			{"Menu Background Color 1", "16;78;139;220"},
			{"Menu Background Color 2", "69;139;0;220"},
			{"Menu Background Darkness (0~1)", 0.8f},

			{"Menu Basic Alpha (0~1)", 0.8f},
			{"Menu Mask Alpha (0~1)", 0.3f},
			{"Menu Shadow", true},
			{"Menu Shadow Thickness", 30.0f},
			{"Menu Shadow Opacity (0~1)", 0.5f},
			MAKE_COMBOBOX("Menu Shadow Color", "Black",
			{NAMED_COLOR_BASE_LIST}),

			{"Menu Font Size", 30},
			{"Menu Line Gap", 10},
			{"Menu Animation Duration (ms)", 200L},
			{"Menu Easing Speed (0~1)", 0.1f},
			{"Menu Round Corners", true},
			{"Menu Roundness", 0.1f},
			{"Menu Icons", true},

			{"Tab Font Size", 30U},
			{"Tab Height", 40U},

			{"Tab Switcher Font Size", 30U},
			{"Tab Switcher Round Corners", true},
			{"Tab Switcher Roundness", 0.3f},
			{"Tab Switcher Shadow", true},
			{"Tab Switcher Shadow Thickness", 40.0f},
			{"Tab Switcher Shadow Opacity (0~1)", 0.5f},
			{"Tab Switcher Opacity (0~1)", 0.7f},

			MAKE_COMBOBOX("Tab Switcher Color", "Black",
				{"Flow", NAMED_COLOR_BASE_LIST}),

			MAKE_COMBOBOX("Tab Switcher Shadow Color", "Black",
				{NAMED_COLOR_BASE_LIST}),

			MAKE_COMBOBOX("Toolbar Color", "White",
				{"Flow", NAMED_COLOR_BASE_LIST}),

			MAKE_COMBOBOX("Apply Folder Attributes", "Query",
				{"Query", "Only Folder", "Recursive"}),

			MAKE_COMBOBOX("Apply Multifile Attributes", "Unify",
				{"Unify", "Toggle"}),

			{"Enable Night Module", true},
			MAKE_COMBOBOX("Night Link Animation", "Fast Fade",
				{"Off", "Fast Fade", "Use Night Effect"}),
			{"Night Link Animation Duration (ms)", 120L},

			{"Go to Parent Folder Hotkey", {{"Keybind", {VK_BACK}}}},
			{"Cancel Selection Hotkey", {{"Keybind", {VK_ESCAPE}}}},
		}
	},

	 {"Window Manager",
		{
			{"Async Enum", true},
			{"Auto Refresh On Open", true},
			{"Enum Cooldown (ms)", 1200L},
			{"Manual Refresh Cooldown (ms)", 5000L},
			{"Enum Max Item Count", 4096},
			{"Enable Night Module", true},
			MAKE_COMBOBOX("Night Link Animation", "Fast Fade",
				{"Off", "Fast Fade", "Use Night Effect"}),
			{"Night Link Animation Duration (ms)", 120L},

			MAKE_COMBOBOX("Sort By", "Window Title",
				{"Window Title", "Process Name", "Process ID", "Process Privilege", "Window Class Name", "Process Description", "Z-Order Band", "Style", "ExStyle"}),
			MAKE_COMBOBOX("Sort Order", "Ascending",
				{"Ascending", "Descending"}),

#ifdef PROFESSIONAL_VERSION
			{"Dynamic Column Width (PRO)", true},
#else
			{"Dynamic Column Width (PRO)", false},
#endif
			{"Anti Suicide", true},

			{"Show Window Icon", true},
			{"Show Process Name", true},
			{"Show Process ID", true},
#ifdef PROFESSIONAL_VERSION
			{"Show Process Privilege (PRO)", false},
#else
			{"Show Process Privilege (PRO)", false},
#endif
			{"Show Window Class Name", true},
			{"Show Attributes", true},
			{"Process Name Rank Color", true},
			{"Show Process Description", false},
#ifdef PROFESSIONAL_VERSION
			{"Show Window Z-Order Band Name (PRO)", false},
#else
			{"Show Window Z-Order Band Name (PRO)", false},
#endif
			{"Show Style", false},
			{"Show ExStyle", false},

			{"Put Invisible Below Visible", true},
#ifdef PROFESSIONAL_VERSION
			{"Pin Topmost Or SpecialBand On Top (PRO)", true},
#else
			{"Pin Topmost Or SpecialBand On Top (PRO)", false},
#endif

			{"Font Size", 28},
			{"Header Font Size", 26},
			{"Row Height", 40},
			{"Wheel Sensitivity", 160.0f},

			{"Easing Speed (0~1)", 0.14f},
			{"Background Alpha (0~1)", 0.68f},
			{"Header Alpha (0~1)", 0.78f},
			{"Row Hover Alpha (0~1)", 0.48f},
			{"Row Select Alpha (0~1)", 0.66f},
			{"Roundness", 0.15f},

			{"Menu Outline Color", "255;185;15;255"},
			{"Menu Background Color 1", "16;78;139;220"},
			{"Menu Background Color 2", "69;139;0;220"},
			{"Menu Background Darkness (0~1)", 0.8f},

			{"Menu Basic Alpha (0~1)", 0.8f},
			{"Menu Shadow", true},
			{"Menu Shadow Thickness", 30.0f},
			{"Menu Shadow Opacity (0~1)", 0.5f},
			MAKE_COMBOBOX("Menu Shadow Color", "Black",
				{NAMED_COLOR_BASE_LIST}),

			{"Menu Round Corners", true},
			{"Menu Roundness", 0.18f},
			{"Menu Font Size", 28},
			{"Menu Line Gap", 8},
			{"Menu Animation Duration (ms)", 200L},
			{"Menu Easing Speed (0~1)", 0.18f},
		}
	},

	 {"Process Manager",
		{
			{"Async Enum", true},
			{"Auto Refresh On Open", true},
			{"Enum Cooldown (ms)", 1200L},
			{"Enum Max Item Count", 4096},
			{"Filter Critical PID <= 4", false},

			MAKE_COMBOBOX("Sort By", "GPU",
				{"PID", "Name", "Threads", "PPID", "CPU", "GPU", "Memory (Private)", "Privilege", "Owner", "Rank", "PPL", "Description", "Profile Description"}),
			MAKE_COMBOBOX("Sort Order", "Descending",
				{"Ascending", "Descending"}),
			MAKE_COMBOBOX("Process Name Color", "Type",
				{"Type", "Dynamic", NAMED_COLOR_BASE_LIST}),
			MAKE_COMBOBOX("Process Path Color Style", "Dynamic",
				{"Static", "Dynamic"}),
 #ifdef PROFESSIONAL_VERSION
			MAKE_COMBOBOX("Show Architecture (PRO)", "Label",
				{"Off", "Column", "Label"}),
 #else
			MAKE_COMBOBOX("Show Architecture (PRO)", "Off",
				{"Off", "Column", "Label"}),
 #endif

			{"Keyword Filter", ""},
			{"Enable Night Module", true},

			MAKE_COMBOBOX("Night Link Animation", "Fast Fade",
				{"Off", "Fast Fade", "Use Night Effect"}),
			{"Night Link Animation Duration (ms)", 120L},
#ifdef PROFESSIONAL_VERSION
			{"Dynamic Column Width (PRO)", true},
#else
			{"Dynamic Column Width (PRO)", false},
#endif
			{"Anti Suicide", true},	// Prevent from killing client itself
			{"Show Process Icon", true},
			{"Show Profile Description", false},
			{"Show Description", true},
			{"Show PPL", false},	// Show Protected Process Light (PPL) Levels

#ifdef PROFESSIONAL_VERSION
			{"Show Process Privilege Tag (PRO)", true},
#else
			{"Show Process Privilege Tag (PRO)", false},
#endif
			{"Simplify Command Line", true},
#ifdef PROFESSIONAL_VERSION
			{"Highlight Process Lifecycle (PRO)", true},
#else
			{"Highlight Process Lifecycle (PRO)", false},
#endif
			{"Lifecycle Highlight Duration (ms)", 3500L},
			{"Pin Lifecycle Rows On Top", false},
			{"Filter Lifecycle Rows By Search", false},
			{"Use Tree Structure", true},
			MAKE_COMBOBOX("Tree Sort Strategy", "Subtree Metric",
				{"Keep Parent First", "Subtree Metric"}),
#ifdef PROFESSIONAL_VERSION
			{"Simplified Columns (PRO)", true},
#else
			{"Simplified Columns (PRO)", false},
#endif

			{"Show PID", true},
			{"Show PPID", true},
			{"Show Threads", true},
			{"Show Rank", true},
			{"Show Path", true},
			{"Show Owner", true},
 #ifdef PROFESSIONAL_VERSION
			{"Show Command Line (PRO)", true},
			{"Show CPU Usage (PRO)", true},
			{"Show GPU Usage (PRO)", true},
			{"Show Memory Usage Private (PRO)", true},
 #else
			{"Show Command Line (PRO)", false},
			{"Show CPU Usage (PRO)", false},
			{"Show GPU Usage (PRO)", false},
			{"Show Memory Usage Private (PRO)", false},
 #endif

			{"Font Size", 30},
			{"Header Font Size", 28},
			{"Row Height", 42},
			{"Line Gap", 6},
			{"Wheel Sensitivity", 160.0f},

			{"Easing Speed (0~1)", 0.14f},
			{"Animation Duration (ms)", 260L},
			{"Background Alpha (0~1)", 0.68f},
			{"Header Alpha (0~1)", 0.78f},
			{"Row Hover Alpha (0~1)", 0.48f},
			{"Row Select Alpha (0~1)", 0.66f},
			{"Roundness", 0.15f},

			{"Menu Font Size", 28},
			{"Menu Line Gap", 8},
			{"Menu Animation Duration (ms)", 200L},
			{"Menu Easing Speed (0~1)", 0.18f},
			{"Menu Roundness", 0.18f},
			{"Menu Alpha (0~1)", 0.88f},
			{"Open File Location Select", true},
		}
	},

	 {"Reg Manager",
		{
			{"Enable Night Module", true},
			MAKE_COMBOBOX("Night Link Animation", "Fast Fade",
				{"Off", "Fast Fade", "Use Night Effect"}),
			{"Night Link Animation Duration (ms)", 120L},
			{"Sync Reg Monitor", false},
			MAKE_COMBOBOX("Reg Monitor Output Placement", "Off",
				{"Off", "Top", "Bottom"}),
			{"Confirm Delete Values", true},
			{"Confirm Delete Keys", true},

			{"Tree Width Ratio (0.2~0.8)", 0.35f},
			{"Tree Row Height", 40},
			{"Value Row Height", 40},
			{"Dynamic Column Width", true},
			{"Tree Auto Refresh Interval (ms)", 30000L},
			{"Wheel Sensitivity", 160.0f},
			{"Easing Speed (0~1)", 0.14f},

			{"Info Font Size", 32},
			{"Value Font Size", 24},

			{"Tab Font Size", 30U},
			{"Tab Height", 40U},
			{"Tab Switcher Font Size", 30U},

			{"Monitor Panel Height", 220},
			{"Monitor Event Display Count", 18},

			{"Editor Font Size", 26},
			{"Editor Width", 620},
			{"Editor Height", 360},
			{"Editor Animation Speed (0~1)", 0.16f},
		}
	},

	{"Disk Missing",
		{
			{"Keep", true},
			{"Signal Cooldown (ms)", 80L},

			MAKE_COMBOBOX("Missing Drives", "System Drive",
				{"System Drive", "All", "Custom"}),

			{"Custom Missing Drives", "D;E"},
		}
	},

	{"Root Program",
		{
			MAKE_COMBOBOX("Policy", "Monitor",
				{"Monitor", "Prevention", "Settle"}),
			MAKE_COMBOBOX("Monitor Reaction", "Notify Delete",
				{"Notify", "Delete", "Notify Delete"}),
			MAKE_COMBOBOX("Prevention Format", "Both",
				{".exe", ".com", "Both"}),
			MAKE_COMBOBOX("Settle Program", "Cmd",
				{"Cmd", "Client", "PowerShell", "Custom"}),
			MAKE_COMBOBOX("Settle Format", ".exe",
				{".exe", ".com"}),
			{"Settle Custom Source Path", ""},
		}
	},

	{"Privacy Spy",
		{
			{"Async", true},
			{"Auto Console", true},
			{"Custom Scan Directory", "D:\\"},
			{"Skip Folders", false},
			{"Skip Readonly Files", true},
			{"Skip Hidden Files", true},
			{"Skip System Files", true},
			{"IDCard Valid Year Min", 1914},
			{"IDCard Valid Year Max", 2024},
			{"IDCard Strict Validify", true},
			{"Person Name Character Max Count", 3},
			{"Filter File Extensions", true},
			{"Included File Extensions", ".txt;.md;.rtf;.doc;.ppt;.xls;.docx;.pptx;.xlsx;.wps;.zip;.rar;.7z;.gz;.c;.cpp;.h;.hpp;.java;.py;.cs;.exe;.sln;.jpg;.png;.bmp;.mp3;.m4a;.mp4;.html;.htm;.css;.js;.db"},

			{"Scan Disk Privacy", true},
			{"Confirm Before Scanning", true},
			{"Find Other Privacy", true},
		}
	},

	{"Privacy Database",
	{
		{"Database Directory", "D:\\Program Files (x86)\\Jackal\\Privacy"}
	}
	},

	{"Self Uninstall",
		{
			MAKE_COMBOBOX("Batch Terminal", "Hide",
				{"Show", "Minimize", "Hide"})
		}
	},

	{"Self Backup",
		{
			{"Async", true}
		}
	},

	{ "Self Restore",
		{
			{"Async", true}
		}
	},

	{"Auto Restore",
		{
			{"Only Backup Folder", true}	//若为 false， 程序将在启动时备份并更新清单
		}
	},

	{"No Cmd",
		{
			MAKE_COMBOBOX("Method", "WINAPI", {"WINAPI", "Reg"}),
			{"Keep", false}
		}
	},

	{"No Taskmgr",
		{
			MAKE_COMBOBOX("Method", "WINAPI", {"WINAPI", "Reg"}),
			{"Keep", false}
		}
	},

	{"No Regedit",
		{
			MAKE_COMBOBOX("Method", "WINAPI", {"WINAPI", "Reg"}),
			{"Keep", false}
		}
	},

	{"No UAC",
		{
			{"Bypass Explorer Notify", true},	// 绕过资源管理器通知
			{"Highest Level When UAC Enabled", false},	//当UAC启用时，是否开到最高级别（默认是第二级别）
			{"Keep", false },		//防止被外界手动关闭
			{"Keep Mode Notify Action", true}
		}
	},

	{"Online Time",
		{
			{"Connect Timeout (s)", 3L},

			MAKE_COMBOBOX("Source", "Taobao",
				{"Taobao", "Time.is", "Suning"}),
		}
	},

	{"IP Tracker",
		{
			{"Update Cooldown (s)", 15.0f},

			MAKE_COMBOBOX("Location", "Province",
				{"Off", "Country", "Province", "Details"}),

			{"Hidden Character", "x"},

			MAKE_COMBOBOX("IP Address", "2",
				{"Off", "All", "3", "2", "1"}),

			MAKE_COMBOBOX("IP Address (v6)", "4",
				{"Off", "All", "7", "6", "5", "4", "3", "2", "1"}),

			MAKE_COMBOBOX("Notify Change", "Notify",
				{"Off", "Notify", "Chatter", "Title", "Speak", "WinToast"}),

			{"Scale", 1.0f},

			{"Show Title", true},

			MAKE_COMBOBOX("IP Address Color", "Pink",
				{"Flow", NAMED_COLOR_BASE_LIST}),

			MAKE_COMBOBOX("Location Color", "Blue",
				{"Flow", NAMED_COLOR_BASE_LIST}),

			{"X Rate", 0.02f},
			{"Y Rate", 0.4f},

			{"Background", true},

			MAKE_COMBOBOX("Background Color", "Black",
				{"Transparent", NAMED_COLOR_BASE_LIST}),

			{"Background Opacity (0~1)", 0.8f},
			{"Background Roundness (0~1)", 0.3f},
			{"Background Shadow", true},
			{"Background Shadow Thickness", 20.0f},
			{"Background Shadow Opacity (0~1)", 0.5f},

			MAKE_COMBOBOX("Background Shadow Color", "Black",
				{NAMED_COLOR_BASE_LIST}),

			{"Give Way to Mouse", true},
		}
	},

	{"IP Address",
		{
			{"Async", true},
			{"Auto Console", true},

			MAKE_COMBOBOX("Method", "Curl",
				{"Curl", "Command"}),

			MAKE_COMBOBOX("External IP Address Source URL", XorStringA("https://api.ip.sb/ip"),
				{
				XorStringA("https://api.ip.sb/ip"),
				"https://www.ipplus360.com/getIP",
				"http://www.ipchicken.com",
				"http://whatismyipaddress.com",
				"http://api.ipify.org"
				}),

		    MAKE_COMBOBOX("IP Location Query Source", "PearAPI",
			{
				"Vore.top",
				"PearAPI",
				"PearAPI High",
				"IQIYI"
			}),

			{"Location Cache Update Cooldown (ms)", 30000L},

			{"Connect Timeout (s)", 5L},
			{"Output Verbose Connection Info", false},
			{"Query External IP", true},
			{"Query External IP Position", true},
			{"AI Generated Description of IP Position", false},
			{"Use HTTPS When Query Position", true},
			{"Output Local IP Details", true},
		}
	},

	{"IP Horror",
		{
			{"Async", true},
			{"Auto Console", true},
			{"Copy to Clipboard", true},
			{"Log Destination Info", true},
			{"Target IP Address", "127.0.0.1"},

			MAKE_COMBOBOX("Method", "V1",
			{"V1", "AI Normal", "AI Mesugaki", "AI Catgirl"})
		}
	},

	{"Phone Area",
		{
			{"Auto Console", true},
			{"Phone Number (actually just need first 7 digits)", 1371111LL},
			{"Connect Timeout (s)", 4L},
			{"Notify", false},
		}
	},

	/*{"Wall Check",
		{
			{"Website", "www.youtube.com"},
			{"Connect Timeout (s)", 10L}
		}
	},*/

	{"Weather Info",
		{
			{"Async", true},
			{"Auto Console", true},
			{"Use Custom QWeather ApiKey", false},
			{"Custom QWeather ApiKey", ""},
			{"Use Custom QWeather ApiHost", false},
			{"Custom QWeather ApiHost", ""},

			MAKE_COMBOBOX("City", "Auto Locate",
				{"Auto Locate", "Custom"}),

			{"Custom City", "北京市"},
			{"Connect Timeout (s)", 10L},
		}
	},

	{"Quake Warning",
		{
			{"Async", true},
			{"Check Cooldown (ms)", 30000L},
			{"Clear Events When Disabled", true},

			MAKE_COMBOBOX("Quake Query Source", "Auto",
			{"Auto", "JMA", "Sichuan", "Fujian", "CENC", "CWA"}),

			MAKE_COMBOBOX("Warning Filter", "Global",
				{"Global", "Domestic", "Province", "City"}),

			MAKE_COMBOBOX("Notify Mode", "Title",
				{"Notify", "Chatter", "Title", "WinToast"}),

			{"Min Warning Intensity", 0.0},          // 新增：最低烈度
			{"Min Warning Magnitude", 0.0},          // 新增：最低震级
			{"Max Warning Event Age (hour)", 3.0},   // 新增：事件超过几小时不再预警

			{"AI Location Validation", false}, // 新增：AI 判断是否在同省同市

			{"Connect Timeout (s)", 10L},
		}
	},

	{"Memeizer",
		{
			MAKE_COMBOBOX("Cut Words", "API",
			{"Single", "Double", "Bili Suggestion", "API", "API 2"}
			),

			MAKE_COMBOBOX("Mode", "Classic",
				{"Standard", "ApiHz", "Classic", "AI"}),
			{"Same Result For Single Word", false},
			{"Standard Pick Chinese Meaning Chance (0~1)", 0.7f},
			{"Standard Meaning Chaos (0~1)", 0.2f},

			{"Exclude Words", "我;你;他;她;它;了;的;不;使;地;得;有;时;候;着;被;把;并;或;而;与;和;于;将;就;可;以;是;都;由;个;一个;吧;呢;吗;呀;哇;哪里;哪;比;从;成;为;到;至;达;往;去;同"}
		}
	},

	{ "Encryptor",
		{
			MAKE_COMBOBOX("Source", "Clipboard",
				{"Fixed", "Clipboard"}),

			{"Fixed Content", "Hello, Jackal!"},

			MAKE_COMBOBOX("Operation", "Encrypt",
				{"Encrypt", "Decrypt"}),

			MAKE_COMBOBOX("Method", "beast",
				{"base64", "crc32", "md5", "sha1", "beast", "beartalk", "abracadabra", "pipa", "pipaplus", "pipasimp", "pipatrad", "pipasimpplus", "pipatradplus", "pipasimpplus2", "pipatradplus2"}),

			{"Copy to Clipboard", true},

			{"Abracadabra Encryptor Path", ""},
		}
,	},

	{ "Reminder",
		{
			MAKE_COMBOBOX("Holiday Greetings", "Basic",
				{"Off", "Basic", "AI"}),
			MAKE_COMBOBOX("Morning Greetings", "Basic",
				{"Off", "Basic", "AI"}),
			MAKE_COMBOBOX("Afternoon Greetings", "Basic",
				{"Off", "Basic", "AI"}),
			MAKE_COMBOBOX("Night Greetings", "Basic",
				{"Off", "Basic", "AI"}),
			MAKE_COMBOBOX("Midnight Greetings", "Basic",
				{"Off", "Basic", "AI"}),
			MAKE_COMBOBOX("Greeting Persona", "Normal",
				{"Normal", "Maid", "Catgirl"}),

			{"Morning Time Min", 6.0f},
			{"Morning Time Max", 10.5f},
			{"Afternoon Time Min", 12.5f},
			{"Afternoon Time Max", 16.8f},
			{"Night Time Min", 18.8f},
			{"Night Time Max", 23.5f},
			{"Midnight Time Min", 0.0f},
			{"Midnight Time Max", 4.0f},
		}
	},

	//{"Bili Cookies",
	//	{
	//		{"Connect Timeout (s)", 3L},
	//	}
	//},

	{"Bili Console",
		{
			{"Auto Console", true},
			{"Debug Output", false},

			{"Draw Periodically", false},
			{"Draw Cooldown (ms)", 500L},
			{"Update Periodically", false},
			{"Update Cooldown (ms)", 180000L},

			{"Use Chinese Number Format", true},

			{"User Medal Wall Display", true},
			{"User Medal Wall X", 110},
			{"User Medal Wall Y", 3},
			{"Show User Space Notice", true},
			{"Show User Like Videos", true},
			{"Show User Coin Videos", true},
			{"Show User Top Video", true},
			{"Show User Masterpieces", true},
			{"Show User Favorite Folders", true},

			{"Single Coin Quantity", 2U},
			{"Like When Coin", true},
		}
	},

	 {"Bili Fans",
		 {
			 {"Async", true},
			 {"User IDs (Sep With Semicolon)", WORMWAKER_MID},
			 {"Update Cooldown (s)", 60L},
			 {"Connect Timeout (s)", 5L},
			 {"HUD", false},
			 {"Hide HUD When Menu On", true},

			 MAKE_COMBOBOX("Action On Failure", "Pause Temporarily", 
			   {"Ignore", "Pause Temporarily", "Disable Module"}),

			 {"Threshold Max", 16U},

			{"Pause Duration (s)", 30L},
			 
			 MAKE_COMBOBOX("HUD Color", "Colorful",
				{NAMED_COLOR_BASE_LIST}),

			{"HUD User Index (Sep With Semicolon)", ""},
			{"HUD Font Size", 30},
			{"HUD Line Gap", 5},
			{"HUD Opacity (0~1)", 0.8f},

			 MAKE_COMBOBOX("HUD Format", "Fans: Number",
				 {"Number", "Fans: Number", "Number Fans", "Name Fans: Number", "Name: Number", "Name: Number Fans"}),

			 MAKE_COMBOBOX("Notify Mode", "Notify",
			 {"Off", "Notify", "Console Output", "Actionbar", "Chatter", "Title", "WinToast", "Speak"}),

			 MAKE_COMBOBOX("Show Fans Nickname (PRO)", "Off",
			 {"Off", "Only Self"}),

			 {"Notify Fans Increase", true},
			 {"Notify Fans Decrease", true},

			 MAKE_COMBOBOX("Fans Change Event", "Sound",
			 {"Off", "Sound", "Command"}),

			 {"Custom Fans Increase Sound", "levelup.wav"},
			 {"Custom Fans Decrease Sound", "pling_low.wav"},

			 {"Custom Fans Increase Command", ""},
			 {"Custom Fans Decrease Command", ""},
			 //{"Notify Prefixes (Sep With Semicolon)", "UP"},

			 {"HUD X Rate", 0.8f},
			 {"HUD Y Rate", 0.75f},

			 //{"PREV DATA", "{}"},
		 }
	 },

	 {"Bili Feed",
		{
			{"Async", true},
			{"Auto Console", true},
			{"Connect Timeout (s)", 5L},
			{"Limit", 100U},

			MAKE_COMBOBOX("Style", "Simple",
				{"Simple", "List", "Fancy"}),
		}
	},

	 {"Bili Hot",
		{
			{"Async", true},
			{"Auto Console", true},
			{"Connect Timeout (s)", 5L},
			{"Limit", 20U},

			MAKE_COMBOBOX("Interface", "Standard",
				{"Standard", "Mobile"}),

			{"Show Heat Score (Standard)", true},
			{"Show Top (Mobile)", true},
		}
	 },

	{"Bili Notifier",
		{
			{"Async", true},

			MAKE_COMBOBOX("Mode", "Notify",
				{"Off", "Notify", "Chatter", "Actionbar", "Title", "WinToast"}
				),

			MAKE_COMBOBOX("Show Reply Content", "Chatter",
			{"Off", "Console Output", "Notify", "Chatter", "Actionbar", "WinToast"}),

			{"Reply Content Max Length", 80U},

			{"Query Cooldown (s)", 5L},
			{"Connect Timeout (s)", 4L},

			{"Ignore Negative Changes", true},

			{"Notify Ats", true},
			{"Notify Chats", true},
			{"Notify Likes", true},
			{"Notify Comments", true},
			{"Notify Coins", true},
			{"Notify Danmaku", true},
			{"Notify Favorites", true},
			{"Notify Uploader Helper Messages", true},
			{"Notify System Messages", true},

			{"PREVIOUS DATA (READONLY)", "{\"at\":0,\"chat\":0,\"coin\":0,\"danmu\":0,\"favorite\":0,\"like\":0,\"recv_like\":0,\"recv_reply\":0,\"reply\":0,\"sys_msg\":0,\"up\":0}"}
		}
	},

			{"Bili Components",
				{
					{"User ID", WORMWAKER_MID},
					{"Output", true},
				}
			},

			{"Bili Profile",
				{
					{"Async", true},
					{"Auto Console", true},
					{"User ID", WORMWAKER_MID},
					{"Connect Timeout (s)", 5L},
					{"Show Like Videos", true},
					{"Show Coin Videos", true},
					{"Show Top Video", true},
					{"Show Masterpieces", true},
					{"Show Space Notice", true},
					{"Show Favourite Folders", true},
					//{"Show Collect Folders", true},
					{"Like Videos Max Shown", 3},
					{"Coin Videos Max Shown", 3},
					{"Masterpieces Max Shown", 3},
				}
			},

			{"Bili Video Cover",
				{
					{"Async", true},
					
					MAKE_COMBOBOX("Mode", "Clipboard Forward", 
					{"Clipboard Forward", "Clipboard Output Link", "Clipboard Download Image"}),

					{"Keep", false},

				}
			},

			{"Bili Video",
				{
					{"Async", true},
					{"Auto Console", true},
					{"AID/BID/Link", ""},

					MAKE_COMBOBOX("Video", "Latest",
						{"Latest", "Custom"}),

					{"User ID", WORMWAKER_MID},

					MAKE_COMBOBOX("Mode", "Once",
						{"Once", "Monitor"}),

					{"No Decrease Notification", false},

					{"Speak Changes", false},

					MAKE_COMBOBOX("Notify Mode", "Chatter",
						{"Off", "Notify", "Chatter", "Actionbar", "Title", "WinToast"}),

					MAKE_COMBOBOX("Notify Prefix", "Title",
					    {"Off", "Module Name", "Title", "BVID"}),

					{"Connect Timeout (s)", 4L},
					{"Query Cooldown (s)", 1L},
				}
			},

			{"Bili Video Helper",
				{
					{"Monitor Web Client", true},
					{"Monitor Desktop Client", true},

					{"Async", true},
					{"Update Cooldown (ms)", 100L},
					{"Data Update Cooldown (ms)", 10000L},
					{"Search Confidence Threshold (0~100)", 97L},

					{"HUD", true},
					{"Hide When Menu On", true},
					{"Give Way to Mouse", true},

					{"Max Web Sessions", 5U},
					{"HUD X Rate", 0.8f},
					{"HUD Y Rate", 0.8f},
					{"HUD Opacity (0~1)", 0.6f},
					{"HUD Scale", 1.0f},

					{"BV Enabled", true},
					{"Cover Enabled", true},
					{"Cover Scale (0~1)", 1.0f},
					{"Cover Opacity (0~1)", 1.0f},
					{"Release Time Difference", true},
					{"Data Line 1", true},
					{"Data Line 2", true},
					MAKE_COMBOBOX("Data Color", "White",
						{NAMED_COLOR_BASE_LIST}),
					MAKE_COMBOBOX("Data Color 2", "Pink",
						{NAMED_COLOR_BASE_LIST}),
					{"Data Changes Display", true},
					MAKE_COMBOBOX("Triple Notify", "Notify",
						{"Off", "Notify", "Chatter", "Speak"}),

					{"Background", false},
					MAKE_COMBOBOX("Background Color", "Black",
						{NAMED_COLOR_BASE_LIST}),
					{"Background Opacity (0~1)", 0.2f},
					{"Background Round Corners", true},
					{"Background Roundness (0~1)", 0.05f},
				}
			},

			{"Bili Settings",
				{
					MAKE_COMBOBOX("Account", "No Account",
						{"No Account"}),
					{"Black Capture When Login", false},
					{"Close Menu When Login", true},
					{"Debug Output", false},
					{"Login QR Code Scale", 6.0f},

					/*{"Cookies (DO NOT LEAK)", ""},
					{"Cookies Json (DO NOT LEAK)", "{}"},
					{"REFRESH TOKEN", ""},*/
				}
			},

			{"Web Settings",
				{
					MAKE_COMBOBOX("Network Online Status Change Notify Mode", "Notify",
						{"Off", "Notify", "Title", "Chatter", "WinToast"}),

					MAKE_COMBOBOX("Network Check Mode", "Default",
						{"Custom", "Default"}),
					{"Network Check Cooldown (ms)", 5000U},
					{"Network Check Custom Website", "http://captive.apple.com/"},
					{"Network Module Force Online", true},
					{"Disable SSL Revocation Check (Schannel)", true},
					{"Realm Update Allow Insecure TLS", false},

					MAKE_COMBOBOX("Output Curl Error", "Non Timeout",
						{"Off", "Non Timeout", "Always"}),
				}
			},

			{"AI Settings",
				{
					MAKE_COMBOBOX("AI Type", "PearAPI",
						{"Spark", "Dashscope", "ChatAnywhere", "PearAPI", "ApiHz", "Local", "Custom"}),

					{"AI Role Prompt", "You are a helpful assistant."},
					{"AI Temperature", 0.3f},
					{"AI Top P", 0.8f},

					MAKE_COMBOBOX("Command /chat Mode Without Arguments", 
						"Input Box",
						{"Input Box", "Clipboard"}),

					{"Command /chat Prompt Prefix", ""},
					{"Command /chat Show Session", true},
					{"Command /chat Force Stream", true},

					{"Local Model", ""},
					{"Local Port", 11434},
					{"Local Route", "/api/chat"},
					{"Local Route (Stream)", "/api/chat"},

					{"Dashscope Use EnvVar ApiKey: DASHSCOPE_API_KEY", true},
					{"Dashscope API Key", "sk-"},

					{"Spark Use EnvVar ApiKey: SPARK_API_KEY", true},
					{"Spark API Key", ""},

					{"ChatAnywhere Use EnvVar ApiKey: CHATANYWHERE_API_KEY", true},
					{"ChatAnywhere API Key", "sk-"},

					{"Custom AI Use EnvVar ApiKey", false},
					{"Custom AI Use EnvVar ApiKey Name", ""},
					{"Custom AI API Key", ""},
					{"Custom AI Base URL", XorStringA("https://")},
					{"Custom AI Model", ""},

					MAKE_COMBOBOX("Dashscope Model", "qwen-turbo",
					{"qwen-turbo", "qwen-long", "qwen-max", "qwen-plus", "qwen-math-plus", "qwen-coder-plus", "qwen-coder-turbo"}),

					MAKE_COMBOBOX("Spark Model", "Spark Lite",
						{ "Spark 4.0 Ultra", "Spark Max", "Spark Max-32K", "Spark Pro", "Spark Pro-128K", "Spark Lite"}),

					MAKE_COMBOBOX("PearAPI Model", "SparkLite",
						{ "SparkLite" }),

					MAKE_COMBOBOX("ApiHz Model", "BaiduLite",
						{ "BaiduTiny", "BaiduLite", "BaiduSpeed", "SparkLite" }),

					MAKE_COMBOBOX("ChatAnywhere Model", "gpt-3.5-turbo",
						{"gpt-3.5-turbo", "gpt-4o-mini", "gpt-4.1-mini", "gpt-4.1-nano", "gpt-5-mini", "gpt-5-nano", "deepseek-r1", "deepseek-v3", "deepseek-v3-2-exp", "gpt-5", "gpt-4o", "gpt-4.1"}),

					MAKE_COMBOBOX("Response Console Output Format", "Markdown",
						{"Markdown", "Markdown With Marks", "Raw", "Plaintext"}),

					{"Debug Output", false},

					MAKE_COMBOBOX("Chat History Default Storage Policy", "Temporary",
						{"Temporary", "Records", "Files"}),

					{"Chat History Sessions Saved in Records (Sep With Semicolon)", ""},
					{"Chat History Sessions Saved in Files (Sep With Semicolon)", "livestream"},

					MAKE_COMBOBOX("Translation", "Off",
					{"Off", "Chinese", "English", "Japanese"}
					),

					{"Filter Keywords (Sep With Semicolon)", ""},

					MAKE_COMBOBOX("Filter (PRO)", "Replace",
						{"Off", "Block", "Filtered", "Replace"}),

					{"Clipboard Tweaks Module Text Processor", false},
					{"Memeizer Processor (PRO)", false},
				}
			},

			{"ApiHz Settings",
				{
					{"ApiHz Custom ID", "88888888"},
					{"ApiHz Custom Key", "88888888"},
					{"ApiHz Use Custom", false},
				}
			},

			{"Agent",
				{
					MAKE_COMBOBOX("Current Instruction", "Run",
						{"Run", "Pause", "Stop"}),

					{ "Pause Task Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_NUMPAD0}}} },

					{"Correct JSON Format", true},
					{"Max Allowed Asks", 100},
					{"Max Allowed File Operations", 100},
					{"Max Allowed Commands", 50},
					{"Max Allowed Repeated Commands", 3},

					MAKE_COMBOBOX("Command Confirmation", "MessageBox",
					{"Always Allow", "AI Basic Check", "MessageBox", "Console"}),

					MAKE_COMBOBOX("File Confirmation", "AI Basic Check",
					{"Always Allow", "AI Basic Check", "MessageBox", "Console"}),

					{"MessageBox Confirm Timeout Enabled", true},
					{"MessageBox Confirm Timeout (ms)", 60000L},

					MAKE_COMBOBOX("MessageBox Confirm Timeout Operation", "Cancel",
						{"Accept", "Decline", "Cancel"}),
					
					{"Output Real Ask", true},
					{"Allow Tool Preparation Missing", false}
				}
			},

			{"Translator",
				{
					{"Module Status Auto Switch", true},

					MAKE_COMBOBOX("Mode", "Edge",
						{"Edge", "PearAPI", "ApiHz", "ApiHz 2",/*"Baidu", "QQ",*/ "AI"}),

					{"AI Prompt", "将冒号后面的文本翻译成{lang}，直接输出即可，不要输出其他任何内容：\n{text}"},
				}
			},
			
			{"Live Stream",
				{
					{"Room ID", 0L},
					{"Auto Toggle LiveChatter Module", true},
					{"Receive Info Data", true},

					{"Gift Update Cooldown (ms)", 5000L},

					{"Gift Check", true},
					{"Gift Triggers Enabled (PRO)", false},
					{"Gift Triggers Config Path", "config/liveStreamGiftTriggers.ini"},
					{"Gift Trigger Default Command", "/bili live chatter Thanks {{nickname}} for {{gift}}[比心]!!!"},
					{"Gift Trigger Default Command Cooldown (ms)", 1000L},

					MAKE_COMBOBOX("Gift Notify Mode", "Notify",
						{"Off", "Notify", "Chatter", "Speak", "Title", "Actionbar", "WinToast"}),

					MAKE_COMBOBOX("Gift Value Display", "Off",
						{"Off", "Gold", "Hamster", "Silver"}),

					MAKE_COMBOBOX("Gift Title Color", "Flow",
						{"Flow", NAMED_COLOR_BASE_LIST}),

					{"Connect Timeout (s)", 8L},

					MAKE_COMBOBOX("Notify Audience Enter", "Off",
						{"Off", "Notify", "Chatter", "Speak", "Title", "Actionbar"}),
#ifdef PROFESSIONAL_VERSION
					MAKE_COMBOBOX("Notify Audience Enter Filter (PRO)", "All",
						{"All", "Fans", "Paid Fans", "Guard"}),
#else
					MAKE_COMBOBOX("Notify Audience Enter Filter (PRO)", "All",
						{"All"}),
#endif

					MAKE_COMBOBOX("Notify Audience Enter Chatter Color", "Colorful",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Notify Audience Leave", "Off",
						{"Off", "Notify", "Chatter", "Speak", "Title", "Actionbar"}),
#ifdef PROFESSIONAL_VERSION
					MAKE_COMBOBOX("Notify Audience Leave Filter (PRO)", "All",
						{"All", "Fans", "Paid Fans", "Guard"}),
#else
					MAKE_COMBOBOX("Notify Audience Leave Filter (PRO)", "All",
						{"All"}),
#endif

					MAKE_COMBOBOX("Notify Audience Leave Chatter Color", "Black",
						{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Audience Name Display", "Default",
						{"Default", "Head", "Head + Tail", "UID", "Netease Nickname"}),

					MAKE_COMBOBOX("Audience Enter Preset", "Enter",
						{"Enter", "Welcome", "Join"}),

					MAKE_COMBOBOX("Audience Leave Preset", "Leave",
						{ "Leave", "Depart"}),

					{"Notify Audience Face Download", false},

					{"HUD", true},
					{"HUD Give Way to Mouse", true},
					{"HUD X Rate", 0.05f},
					{"HUD Y Rate", 0.2f},
					{"HUD Information Font Size", 30},
					{"HUD Online Audience Animation Speed", 6.0f},
					{"HUD Show Basic Information", true},
					{"HUD Show Online Audience", true},

					MAKE_COMBOBOX("HUD Online Audience Query Source", "Front-end",
						{"Gold Rank API", "Front-end"}),

					{"HUD Online Audience Query API Host UID", WORMWAKER_MID},
					{"HUD Online Audience Query API Page Size", 2},
					{"HUD Online Audience Update Cooldown (ms)", 8000L},
					{"HUD Online Audience Max Count", 12U},
					{"HUD Online Audience Cache Size", 30},
					{"HUD Online Audience Nickname Font Size", 20},
					{"HUD Online Audience Face", true},
					{"HUD Online Audience Face Circle", true },
					{"HUD Online Audience Face Update Cooldown (d)", 7},
					{"HUD Online Audience Line Gap", 35},

					{"HUD Online Audience Background", true},
					{"HUD Online Audience Background Unification", true },
					{"HUD Online Audience Background Roundness", 0.3f},
					{"HUD Online Audience Background Round Corners", true },
					{"HUD Online Audience Background Opacity (0~1)", 0.5f},
					{"HUD Online Audience Background Shadow", true },
					{"HUD Online Audience Background Shadow Thickness", 20.0f },
					{"HUD Online Audience Background Shadow Opacity (0~1)", 0.5f },

					MAKE_COMBOBOX("HUD Online Audience Background Color", "Black",
						{"Flow", NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("HUD Online Audience Background Shadow Color", "Black",
						{NAMED_COLOR_BASE_LIST }),

					MAKE_COMBOBOX("HUD Online Audience Time Mode", "Absolute",
						{"Off", "Absolute", "Relative", "Level System"}),

					MAKE_COMBOBOX("Audience Level Upgrade Congratulations", "Real Chatter",
					{"Off", "Chatter", "Notify", "Title", "Real Chatter", "Speak", "WinToast"}),

					{"Audience Level System Only Followers", true},
					{"Audience Level System Speed", 1.0f},
					{"Audience Level Up Only When Host is Present", true},
					{"Wipe Audience Profile If Not Fans", true},
					{"HUD Online Audience Max Absolute Time (min)", 240},
				}
			},

			{"Streamer",
				{
					{"Async", true},
					{"Sync Bili Live Status", true},
					{"Update Cooldown (ms)", 8000L},

					{"Toggle Bili Live Status (PRO)", false},
					{"Announce Start/Stop to IRC (PRO)", false},
					{"Toggle LiveStream Module", true},
					{"Disconnection Warning", true},
					{"Room Title (READONLY)", ""},

					MAKE_COMBOBOX("Bili Live Platform", "pc_link",
					{"pc_link", "web_link", "android_link"}),

					MAKE_COMBOBOX("Bili Live Area", "Current",
					{"Current", "Indie Game", "Other Standalones", "Console Games", "Minecraft", "Terraria", "CS:GO", "Science", "Virtual", "Custom"}),

					{"Param version", "1.0.0"},
					{"Param build", 1234L},

					{"Bili Live Area Custom Id", 701L},

					MAKE_COMBOBOX("Bili Live Stream Key Output", "Both",
					{"Off", "Copy", "Console Output", "Both"}),
				}
			},

			{"QQ Bot",
				{
					{"Scan Cooldown (ms)", 5000L},
					{"Others Message Max X Rate", 0.4f},
					{"Own Message Min X Rate", 0.41f},
					{"Recognize Min Confidence (0~100)", 80.0f},
				}
			},

			{"QQ Inspect",
				{
					{"Async", true},
					{"Auto Console", true},
					{"Connect Timeout (s)", 3L},
					{"Close Menu", true},
					{"Notify Basic Info", false},
					{"Notify Others", false},
					{"Output Steps", false},
					{"Output Verbose Connection Info", false},
					{"Scan Port Min", 4300},
					{"Scan Port Max", 4305},
					{"Group Member Page Size", 10L},
					{"Group Member Max Pages", 200L},
					{"Request Delay Min (ms)", 900L},
					{"Request Delay Max (ms)", 1600L},
				}
			},

			{"QQ Bind Query",
				{
					{"Async", true},
					{"Auto Console", true},
					{"QQ Number", "114514"},
					{"Query Microblog", true},
					{"Connect Timeout (s)", 3L},
				}
			},

			{"System Proxy",
				{
					{"Proxy Server", ""},
					{"Proxy Override", ""},
					{"Options Sync Cooldown (ms)", 10000L},
					{"Notify", true},
					//{"Config Auto Sync", true},
				}
			},

			{"ScreenSaver",
				{
					{"Use Custom Program", false},
					{"Your Custom Program", "null"},
					{"Display On Client", true},
					{"Disable ForceTopmost", true},
					{"Disable Night", true},
					{"Disable Gamma", false},
					{"Close Client Menu", true},
					{"Mute", true},
					{"Key Locker (Press END to quit)", false},
					{"Mouse Disabler (Press END to quit)", false},
				}
			},

			{"No ScreenSaver",
				{
					{"Check Process", true},
					{"Kill Process", false}
				}
			},

			{"No Animation",
				{
				}
			},

			{"Mouse ESP",
				{
					{"Visibility Check", true},
					{"Circle", false},
					{"Circle Radius", 25.0f},
					{"Circle Opacity (0~1)", 0.3f},
					
					{"Box", false},
					{"Box Easing", true},
					{"Box Easing Speed (0~1)", 0.2f},
					{"Box Line Width", 2},
					{"Box Width Rate", 1.0f},
					{"Box Height Rate", 1.2f},
					{"Box Opacity (0~1)", 0.8f},
					{"Box Rounded Corners", true},

					{"Coordinates", false},
					{"Coordinates Font Size", 30},
					{"Coordinates Opacity (0~1)", 0.5f},
					{"Coordinates X Offset", 5},
					{"Coordinates Y Offset", 5},

					MAKE_COMBOBOX("Particles", "Both",
					{"Off", "Click", "Continuous", "Both"}),

					{"Particles Amount (Continuous)", 1.0f},
					{"Particles Amount (Click)", 20.0f},

					MAKE_COMBOBOX("Particles Color (Continuous)", "Rainbow",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Particles Color (Click)", "Colorful",
					{NAMED_COLOR_BASE_LIST}),

					{"Particles Color Jitter", 0.8f},

					MAKE_COMBOBOX("CPS Display", "Off",
					{"Off", "CPS Left | Right", "Left | Right", "Left", "Right"}),

					{"CPS Opacity (0~1)", 0.5f},
					{"CPS Font Size", 30},

					MAKE_COMBOBOX("Box Color", "Rainbow",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Circle Color", "Yellow",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Circle Color (Left Click)", "Blue",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Circle Color (Right Click)", "Pink",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Circle Color (Middle Click)", "Red",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Coordinates Color", "Rainbow",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("CPS Color", "Aqua-Pink",
					{NAMED_COLOR_BASE_LIST}),
				}
			},

			{"Mouse Trails",
				{
					{"Trails", 5},
				}
			},

			{"Spotlight",
				{
					{"Mask Alpha (0~1)", 0.75f},
					{"Circle Alpha (0~1)", 0.7f},

					{"Animation Duration (ms)", 700L},
					{"Circle Radius", 75.0f},

					MAKE_COMBOBOX("Mask Color", "Black",
					{NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Circle Color", "White",
					{NAMED_COLOR_BASE_LIST}),
				}
			},

			{"Crosshair",
				{
					{"Advanced Mode", false},
					{"Advanced Mode Show HUD", true},
					{"Advanced Mode Hotkey", {{"Keybind", {VK_LMENU, VK_RMENU}}}},
					{"Advanced Mode Allow No Focus", false},
					{"Crosshair Line Width", 2},
					{"Crosshair Line Opacity (0~1)", 0.9f},
					{"Crosshair Hollow Enabled", true},
					{"Crosshair Hollow Radius", 80},

					MAKE_COMBOBOX("Crosshair Line Color", "Rainbow",
						{"White", "Red", "Green", "Blue", "Magenta", "Colorful", "Rainbow"}),

					{"Crosshair Line Wave Color", true},

					MAKE_COMBOBOX("Crosshair Line Combination Type", "Plus",
						{"Horizontal", "Vertical", "Plus", "X", "Plus & X"}
						),

					{"Coord Font Size", 30},
					{"HUD Font Size", 25},
					{"HUD Line Gap", 5},
					{"HUD Opacity (0~1)", 0.9f},
					{"Hide When Menu On", false},
				}
			},

			{"Keystrokes",
				{
					MAKE_COMBOBOX("Text Color", "Rainbow",
						{"Flow", NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Outline Color", "Rainbow",
						{"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),

					MAKE_COMBOBOX("Background Color", "Black",
						{"Transparent", NAMED_COLOR_BASE_LIST}),

					{"X Rate", 0.9f},
					{"Y Rate", 0.7f},
					{"Box Size", 54},
					{"Box Gap", 15},
					{"Box Opacity (0~1)", 1.0f},
					{"Pressed Box Opacity (0~1)", 1.0f},
					{"Outline Opacity (0~1)", 1.0f},
					{"Text Opacity (0~1)", 1.0f},
					{"Font Size", 43},
					{"Space", true},
					{"Shift", true},
					{"Mouse Buttons", true},
					{"Hide When Menu On", false},
					{"Show CPS", true},
					{"Give Way to Mouse", true},
					{"Easing Speed (0~1)", 0.1f},
					{"Round Corners", false},
					{"Roundness", 0.2f},
					{"Shadow", true},
					{"Shadow Thickness", 20.0f},

					MAKE_COMBOBOX("Shadow Color", "Black", {NAMED_COLOR_BASE_LIST})
				}
			},

{"Keystrokes2",
	{
		//{"Instant Tips", true},
		{"Box Width", 55},
		{"Box Height", 70},
		{"Box Gap", 15},
		{"Box Opacity (0~1)", 1.0f},
		{"Pressed Box Opacity (0~1)", 1.0f},
		{"Outline Opacity (0~1)", 1.0f},
		{"Text Opacity (0~1)", 1.0f},

		MAKE_COMBOBOX("Text Color", "Rainbow",
			{"Flow", NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Outline Color", "Rainbow",
			{"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Background Color", "Black",
			{"Transparent", NAMED_COLOR_BASE_LIST}),

		{"Font Size Rate", 1.5},
		{"Bigger Font Size Of Single Char Key", false},
		{"X Rate", 0.5f},
		{"Y Rate", 0.87f},

		MAKE_COMBOBOX("Alignment", "Center",
			{"Center", "Left", "Right"}),

		{"Hide When Menu On", false},
		{"Easing Speed (0~1)", 0.1f},
		{"Show Exit Animation", true},
		{"Exit Animation Duration (ms)", 220L},
		{"Key Display Max Count", 10U},

		MAKE_COMBOBOX("Key Display Order", "Layout",
			{"ASCII", "List Forward", "List Backward", "Layout"}),

		{"Multi Row Mode", false},
		{"Multi Row Row Gap", 45},                  // 每排之间的垂直距离
		{"Multi Row Offset (-1~1)", -0.3f},         // 排与排之间的横向错位
		MAKE_COMBOBOX("Multi Row Vertical Sort (PRO)", "Top",
			{"None", "Top", "Bottom"}),

		{"Multi Row Fog Enabled", false},
		{"Multi Row Fog Intensity (0~1)", 0.6f},

		{"Bigger Pressed", true},
		{"Give Way to Mouse", true},
		{"Give Way to Mouse Distance", 200.0},
		{"Show Number Below", true},
		{"Number Display Recent", true},
		{"Number Color Show Recent", true},
		{"Hide Mouse Buttons", false},
		{"Hide F13-F24", true},
		{"Toggle KeyReaction Module", true},

		{"Round Corners", false},
		{"Roundness", 0.2f},
		{"Shadow", true},
		{"Shadow Thickness", 20.0f},

		{"Start Pos X Rate Min", 0.4f},
		{"Start Pos X Rate Max", 0.6f},
		{"Start Pos Y Rate Min", 1.0f},
		{"Start Pos Y Rate Max", 1.1f},

		MAKE_COMBOBOX("Rain Effect", "Off", 
		{"Off", "Rise", "Fall"}),

		MAKE_COMBOBOX("Rain Effect Coordinate Mode", "Independent",
			{"Follow Key Box", "Independent"}),

		MAKE_COMBOBOX("Rain Effect Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),

		{"Rain Effect Opacity (0~1)", 0.5f},
		{"Rain Effect Whiteness (0~1)", 0.8f},
		{"Rain Effect Width Rate (0~1)", 0.8f},
		{"Rain Effect Height", 250},
		{"Rain Effect Fade Height", 60},
		{"Rain Effect Speed", 10.0f},

		MAKE_COMBOBOX("Shadow Color", "Black", {NAMED_COLOR_BASE_LIST})
	}
},

{"Letter Graph",
{
	MAKE_COMBOBOX("Sort By", "Name",
		{"Name", "Code", "Count"}),

	{"Adaptive Height Scaling", true},
	{"Bar Max Height", 500},

	{"Bar Opacity (0~1)", 0.3f},
	{"Bar Width Fill Mode", false},
	{"Bar Width", 50},
	{"Bar Gap", 10},

	{"Key Max Value", 1024},

	{"Text Opacity (0~1)", 0.7f},
	{"Text Font Size", 50},

	{"Easing", true},
	{"Easing Speed (0~1)", 0.2f},

	MAKE_COMBOBOX("Bar Direction", "Right",
		{"Right", "Up", "Left", "Down"}),

	MAKE_COMBOBOX("Bar Color 1", "Green",
		{NAMED_COLOR_BASE_LIST}),
	MAKE_COMBOBOX("Bar Color 2", "Red",
		{NAMED_COLOR_BASE_LIST}),
	MAKE_COMBOBOX("Key Color", "Colorful",
		{NAMED_COLOR_BASE_LIST}),
	MAKE_COMBOBOX("Value Color", "Pink",
		{NAMED_COLOR_BASE_LIST}),

	{"Stat Lyrics", true},
	{"Stat Keys", true},

	{"Base X Rate", 0.2f},
	{"Base Y Rate", 0.5f},
	{"X Offset", 0.0f},
	{"Y Offset", 0.0f}
}
},

{"Clipboard ESP",
	{
		{"Font Size", 20},
		{"Line Gap", 3},
		{"Max Lines Shown", 25},
		{"Text Background", false},
		{"Background", true},
		{"Background Round Corners", true},
		{"Background Roundness", 0.2f},
		{"Background Opacity (0~1)", 0.5f},
		{"Background Shadow", true},
		{"Background Shadow Thickness", 24.0f},
		{"Background Shadow Opacity (0~1)", 0.45f},
		MAKE_COMBOBOX("Background Color", "Black",
		{"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Background Shadow Color", "Black",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Text Color", "Gold",
		{NAMED_COLOR_BASE_LIST}),
		{"Show Bitmap Preview", true},
		{"Bitmap Preview Max Width", 420},
		{"Bitmap Preview Max Height", 260},
		{"Bitmap Preview Border", true},
		{"Bitmap Preview Border Width", 2.0f},
		MAKE_COMBOBOX("Bitmap Preview Border Color", "White",
		{NAMED_COLOR_BASE_LIST}),
		{"Show Format", true},
		{"Show Line Number", true},
		{"Show Text Stats", true},
		{"Max Width Rate (0~1)", 0.3f},
		{"Give Way to Mouse", true},
		{"Hide When Menu On", true},
		{"X Rate", 0.16},
		{"Mid Y Rate", 0.3},
	}
},

{"Security ESP",
	{
		{"Hide When Menu On", true},
		{"Give Way to Mouse", true},
		{"Show Description When Mouse Hovering", true},
		{"Background", true},
		{"Background Round Corners", true},
		{"Background Roundness", 0.2f},
		{"Background Opacity (0~1)", 0.5f},
		{"Background Shadow", true},
		{"Background Shadow Thickness", 26.0f},
		{"Background Shadow Opacity (0~1)", 0.45f},
		MAKE_COMBOBOX("Background Color", "Black",
		{"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Background Shadow Color", "Black",
		{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Title Color", "Red",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Malware Text Color", "Red",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Antivirus Text Color", "Gold",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Description Text Color", "Aqua",
		{NAMED_COLOR_BASE_LIST}),

		{"HUD Font Size", 30},
		{"HUD Line Gap", 5},
		{"X Rate", 0.8},
		{"Mid Y Rate", 0.5},
	}
},

{"PPL ESP",
	{
		{"Hide When Menu On", true},
		{"Give Way to Mouse", true},
		MAKE_COMBOBOX("Notify Changes", "Notify",
		{"Off", "Notify", "Chatter", "Console Output"}),

		{"Background", true},
		{"Background Round Corners", true},
		{"Background Roundness", 0.2f},
		{"Background Opacity (0~1)", 0.5f},
		{"Background Shadow", true},
		{"Background Shadow Thickness", 26.0f},
		{"Background Shadow Opacity (0~1)", 0.45f},
		MAKE_COMBOBOX("Background Color", "Black",
		{"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Background Shadow Color", "Black",
		{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Title Color", "Gold",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("PPL-Light Text Color", "Green",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("AM-Light Color", "Aqua",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("LSA-Light Color", "Purple",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Windows Color", "Blue",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("WinTcb-Light Color", "Green",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("WinTcb Color", "Red-Orange",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("WinSystem Color", "Red",
		{NAMED_COLOR_BASE_LIST}),

		{"HUD Font Size", 24},
		{"HUD Line Gap", 5},
		{"X Rate", 0.02f},
		{"Mid Y Rate", 0.35f},
	}
},

	{"Performance HUD",
		{
			{"Hide When Menu On", true},
			{"Give Way to Mouse", true},

			{"X Rate", 0.02f},
		{"Y Rate", 0.2f},
		{"Text Opacity (0~1)", 1.0f},
		{"Line Gap", 5},
		{"Font Size", 24},

		{"Title", true},
		MAKE_COMBOBOX("Title Color", "Gold",
		{NAMED_COLOR_BASE_LIST}),

		{"Background", true},
		MAKE_COMBOBOX("Background Color", "Black",
		{"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),
		{"Background Opacity (0~1)", 0.55f},
		{"Background Shadow", true},
		{"Background Shadow Opacity (0~1)", 0.4f},
		{"Background Shadow Thickness", 20.0f},

		MAKE_COMBOBOX("Key Color", "Purple",
		{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Client Value Color", "Dynamic",
		{"Dynamic", NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("System Value Color", "Dynamic",
		{"Dynamic", NAMED_COLOR_BASE_LIST}),

		{"Easing", true},
		{"Update Cooldown (ms)", 2000L},

		MAKE_COMBOBOX("CPU Display", "Both",
		{"Off", "Both", "Client", "System"}),
		MAKE_COMBOBOX("GPU Display", "Both",
		{"Off", "Both", "Client", "System"}),
		MAKE_COMBOBOX("Memory Display", "Both",
		{"Off", "Both", "Client", "System"}),
		MAKE_COMBOBOX("Network Display", "Both",
		{"Off", "Both", "Client", "System"}),

		MAKE_COMBOBOX("Basic Style", "Classic",
		{"Classic"}),

		MAKE_COMBOBOX("CPU Number Style", "Percentage Full",
		{"Percentage", "Percentage Full"}),
		MAKE_COMBOBOX("GPU Number Style", "Percentage Full",
		{"Percentage", "Percentage Full"}),

		MAKE_COMBOBOX("Memory Number Style", "Percentage Full",
		{"Percentage", "Percentage Full", "Value", "Value Full"}),
		MAKE_COMBOBOX("Network Number Style", "Value Full",
		{"Percentage", "Percentage Full", "Value", "Value Full"}),

		{"Value Precision", 2},
	}
},

{"Download HUD",
	{
		{"Hide When Menu On", false},
		{"Give Way to Mouse", true},

		{"X Rate", 0.7f},
		{"Y Rate", 0.1f},

		{"Title", true},

		{"Item Width", 350.0f},
		{"Item Height", 120.0f},
		{"Item Width Strict", true},

		{"Item Gap", 40.0f},
		{"Item Easing", true},
		{"Item Easing Speed (0~1)", 0.2f},
		{"Item Fade Duration (ms)", 1000L},
		{"Item Max Count", 8U},

		{"Text Font Size", 25},
		{"Text Opacity (0~1)", 1.0f},

		{"Background", true},
		{"Background Round Corners", true},
		{"Background Roundness", 0.5f},
		{"Background Opacity (0~1)", 0.8f},
		{"Background Shadow", true},
		{"Background Shadow Thickness", 30.0f},
		{"Background Shadow Opacity (0~1)", 0.5f},

		MAKE_COMBOBOX("Background Color", "Black",
		{"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Background Shadow Color", "Black",
		{NAMED_COLOR_BASE_LIST}),

		{"Progress Bar Easing", true},
		{"Progress Bar Easing Speed (0~1)", 0.07f},
		{"Progress Bar Height", 10},

		{"Completed Task Show Time (ms)", 5000L},
	}
},

{"PPL ESP",
	{
		{"Hide When Menu On", true},
	}
},

{"MC Display",
	{
		MAKE_COMBOBOX("Crosshair", "Vanilla",
			{"Off", "Vanilla"}),

		MAKE_COMBOBOX("Crosshair Color", "Smart",
			{"Smart", NAMED_COLOR_BASE_LIST}),

		{"Crosshair Scale", 1.0f},
		{"Crosshair Opacity (0~1)", 1.0f},

		{"Hide When In Minecraft", false},
		{"Hand Enabled", true},
		//{"Hand 3D Mode", false},
		{"Hand Scale", 6.0f},
		{"Hand Texture Name", "iron_sword.png"},
		{"Hand X Addition", 0.0f},
		{"Hand Y Addition", 0.0f},
		{"Hand Move X Range", 400.0f},
		{"Hand Move Y Range", 1000.0f},
		{"Hand Rotation Base (Degrees)", -150.0f},
		{"Hand Rotation Turn Coefficient (0~1)", 0.35f},
		{"Hand Opacity (0~1)", 1.0f},

		MAKE_COMBOBOX("Hand Left Click Action", "Wield",
			{"Off", "Wield"}),

		{"Hand Wield Action Rotation Changes (Degrees)", 25.0f},
		{"Hand Left Click Action Duration (ms)", 400L},

		MAKE_COMBOBOX("Hand Right Click Action", "Block",
			{"Off", "Block"}),

		{"Hand Block Action Rotation Changes (Degrees)", -45.0f},
	}
},

{"Minecraft Utils",
	{
		/*{"Logger", true},
		MAKE_COMBOBOX("Logger Exceptions", "Notify",
		{"Off", "Notify", "Chatter"}),*/

		{"Auto Sprint (Forward)", true},
		{"Auto Sprint (Attack)", true},

		MAKE_COMBOBOX("In Game Detection", "Auto",
		{"Auto", "Cursor Visibility", "Mouse Capture", "Window Center"}),

		{"Window Center Radius", 100.0f},

		MAKE_COMBOBOX("Key Input Method", "SendInput",
		{"SendInput", "WMessage", "Simulation"}),

#ifdef PROFESSIONAL_VERSION
		{"Save Move Keys (PRO)", true},
#else
		{"Save Move Keys (PRO)", false},
#endif
		{"Save Move Keys Release Interval (ms)", 10L},

		{"Log Parser Utilities", true},
		{"Log Parser UTF-8", true},
		{"Log Parser Notify", false},
		{"Log Parser Update Cooldown (ms)", 300L},
		{"Log Cache Max Lines", 32L},

		MAKE_COMBOBOX("Log Game Chat Output Mode (PRO)", "Island",
		{"Off", "Notify", "Chatter", "Title", "Speak", "Island", "Real Chatter"}),

		MAKE_COMBOBOX("Log Game Chat Chatter Type", "Top",
		{"Scroll", "Top", "Bottom", "Reverse", "Horizontal", "Vertical", "Random"}),	// 弹幕类型

		MAKE_COMBOBOX("Log Game Chat Chatter Color", "Colorful",
		{NAMED_COLOR_BASE_LIST}),

		{"Log Game Chat Speak Translator", false},
		{"Log Game Chat Output Filter", true},

		MAKE_COMBOBOX("Log Game Chat Output Filter Mode", "Warn & Block",
		{"Block", "Replace", "Warn", "Warn & Block"}),

		MAKE_COMBOBOX("Input Method (Game)", "Ignore",
		{"Ignore", "Off"}),

		MAKE_COMBOBOX("Input Method (Chat)", "Ignore",
		{"Ignore", "Off", "On"}),

		MAKE_COMBOBOX("Input Method (Command)", "Ignore",
		{"Ignore", "Off"}),

		{"Auto Read Keybinds", true},
		{"Auto Read Cooldown (ms)", 60000L},

		{"Attack Key", {{"Keybind", {VK_LBUTTON}}}},
		{"Use Key", {{"Keybind", {VK_RBUTTON}}}},
		{"Forward Key", {{"Keybind", {'W'}}}},
		{"Left Key", {{"Keybind", {'A'}}}},
		{"Backward Key", {{"Keybind", {'S'}}}},
		{"Right Key", {{"Keybind", {'D'}}}},
		{"Jump Key", {{"Keybind", {VK_SPACE}}}},
		{"Sneak Key", {{"Keybind", {VK_LSHIFT}}}},
		{"Sprint Key", {{"Keybind", {VK_LCONTROL}}}},
		{"Inventory Key", {{"Keybind", {'E'}}}},
		{"Chat Key", {{"Keybind", {'T'}}}},
		{"Command Key", {{"Keybind", {VK_OEM_2}}}},
	}
},

{"Auto Text",
	{
		{"Auto GG (PRO)", true},

		MAKE_COMBOBOX("Auto GG Mode", "Smart Send",
		{"Smart Send", "Copy", "Chatter", "Speak", "WinToast", "Real Chatter"}),

		{"Auto GG Content (Victory)", "gg"},
		{"Auto GG Content (Defeat)", "gg"},

		MAKE_COMBOBOX("Password Source", "Fixed",
		{"Fixed", "File"}),

		{"Password (Fixed)", "123456"},
		{"Password File Path", ""},

		{"Auto Register (PRO)", false},
		{"Auto Login (PRO)", false},

		{"Auto Talk Back (Experimental)", false},

		MAKE_COMBOBOX("Auto Thank Watchdog Mode", "Smart Send",
		{"Smart Send", "Copy", "Chatter", "Speak", "WinToast", "Real Chatter"}),

		{"Auto Thank Watchdog", true},
		{"Auto Thank Watchdog Content (Hypixel)", "Thanks Watchd0g!!!"},
		{"Auto Thank Watchdog Content (Heypixel)", "少羽牛逼"},
	}
},

{"Auto L",
	{

		MAKE_COMBOBOX("Source", "Preset",
		{"Fixed", "List Random Element", "File Random Line", "Preset"}),

		MAKE_COMBOBOX("Detect Kills", "Death",
		{"Death", "PVP"}),

		MAKE_COMBOBOX("Detect Speak", "Pattern",
			{"Pattern", "AI", "Mixed"}),

		{"Fixed Content", "一破，卧龙出山！{player} 已被 Wurst 击毙"},
		{"Content List", "{player} ꮮ;{player} ꮮꮮ;{player} ꮮꮮⅬ"},
		{"File Path", ""},

		MAKE_COMBOBOX("Preset", "Mesugaki (Chinese)",
		{"Mesugaki (Chinese)", "Mesugaki (English)", "Mesugaki (Japanese)", "Normal Chinese", "Normal English"}),

		{"Add Target Name", true},

		MAKE_COMBOBOX("Name Transform", "Lower Case 2",
		{"Off", "Lower Case", "Upper Case", "Annoying Case", "Lower Case 2"}),
		
		{"Includes Player Speak", false},
		{"Includes Void Falling", true},
		{"Includes Falling", true},
		{"Includes Spear Penetration", true},
		{"Includes Mace Smashing", true},
		{"Includes Burnt", true},
		{"Includes Lava", true},
		{"Includes Nonfinal Kills", true},
		{"Includes Final Kills", true},
		{"Includes Bed Destruction", false},
		{"Includes Team Elimination", false},
		{"Trigger Cooldown (ms)", 800L},
		{"Event Dedup Cooldown (ms)", 2200L},

		{"Player Blacklist (Sep With Semicolon)", ""},
		{"Player Blacklist Keywords (Sep With Semicolon)", "Owner;Admin"},

		MAKE_COMBOBOX("Anti Spam Style", "Off",
			{"Off", "Normal", "Japanese"}
		),

		{"Remove Decoration", false},

		MAKE_COMBOBOX("Length Limit Mode", "Off",
			{"Off", "Fallback", "Filter", "Ellipsis", "Cut"}),

		{"Length Limit", 60L},

		MAKE_COMBOBOX("Format", "Direct",
		{"Direct", "/shout", "/pc", "@", "/title", "/tellraw", "actionbar"}),

		MAKE_COMBOBOX("Mode", "Smart Send",
		{"Smart Send", "Copy", "Chatter", "Speak", "WinToast", "Real Chatter"}),
	}
},

{"Chat Queue",
	{
		{"Hide HUD When Menu On", false},

		{"Pause Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, '0'}}}},
		{"Clear Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, 'F'}}}},
		{"Send Queue Front Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_ADD}}}},
		{"Discard Queue Front Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_SUBTRACT}}}},

		{"Chat Send Required Idle Time (ms)", 1500L},
		{"Chat Send Cooldown (s)", 20.0f},
		{"Chat Send Task Lifetime (s)", 30.0f},
		{"Block Keyboard While Sending", true},
		{"Block Keyboard Duration (ms)", 3000L},
		{"Clear Clipboard After Sending", true},

		{"Target Unique Message", true},
		{"Clear When Bed Destroyed", true},
		{"Clear When Team Eliminated", true},

		{ "HUD", true},
		MAKE_COMBOBOX("HUD Queue Source", "Both",
			{"Minecraft", "Bilibili", "Both"}),
		MAKE_COMBOBOX("HUD Dual Queue Layout", "Minecraft Left",
			{"Minecraft Left", "Bilibili Left"}),

		{ "HUD Title", true },
		{ "HUD Max Items", 5 },
		{ "HUD Current Instance Only", true },

		{ "HUD Hide Auto Account", true },   // ★ 默认隐藏自动注册/登录
		{ "HUD Hide Auto L", false },

		// ===============================
		// ++
		// 位置 & 尺寸
		// ===============================

		{ "HUD X Rate", 0.7f },   
		{ "HUD Y Rate", 0.1f },   

		{ "HUD Item Width", 300 },
		{ "HUD Item Height", 60 },
		{ "HUD Item Gap", 10 },

		{ "HUD Item Width Strict", false },

		// ===============================
		// 字体 & 文本
		// ===============================

		{ "HUD Text Font Size", 25 },
		{ "HUD Text Opacity (0~1)", 1.0f },

		// ===============================
		// 背景
		// ===============================

		{ "HUD Background", true },
		{ "HUD Background Round Corners", true },

		// combobox
		MAKE_COMBOBOX(
			"HUD Background Color",
			"Black",
			{ "Transparent", NAMED_COLOR_BASE_LIST}
		),

		{ "HUD Background Opacity (0~1)", 0.55f },
		{ "HUD Background Roundness", 0.35f },

		// ===============================
		// 阴影
		// ===============================

		{ "HUD Background Shadow", true },
		{ "HUD Background Shadow Thickness", 2.0f },

		MAKE_COMBOBOX(
			"HUD Background Shadow Color",
			"Black",
			{NAMED_COLOR_BASE_LIST}
		),

		{ "HUD Background Shadow Opacity (0~1)", 0.45f },

		// ===============================
		// 动画参数（★重点）
		// ===============================

		{ "HUD In Sharpness", 16.0f },     // 出现速度
		{ "HUD Out Sharpness", 20.0f },    // 消失稍快一点
		{ "HUD Move Sharpness", 18.0f },   // 队列滑动

		{ "HUD Leave Max Time (ms)", 2200L },
		{ "HUD Time Countdown", true},

		MAKE_COMBOBOX("HUD Highlight Cooldown", "Override",
		{"Off", "Override", "Color"}),
	}
},

{"Motion Blur",
	{
		/*MAKE_COMBOBOX("Mode", "Accumulation",
			{"Superposition", "Accumulation"}
			),*/

		MAKE_COMBOBOX("Apply Area", "Screen",
			{"Client Only", "Screen"}),

		//{"Accumulation Alpha Blend (0~1)", 0.2f},

		MAKE_COMBOBOX("Apply Model", "Exponential",
			{"Gaussian", "Exponential"}),

		{"Update Cooldown", 40},
		{"Frame Count", 5},
		{"Gaussian Sigma", 0.9f},
		{"Exponential Lambda", 0.5f},
		{"Darken When Blur", true},
		{"Gaussian Darken Amount (0~1)", 0.4f},
		{"Exponential Darken Amount (0~1)", 0.45f},

		{"Blur Enabled", false},
		{"Blur Strength", 2.0f},
		{"Blur Samples", 5},
		{"Blur Once", true},
		{"Blur Alpha Boost (0~1)", 0.0f},
		{"Blur Brightness Boost (0~1)", 0.3f},

		{"Redraw Client Texture", true},
		{"Test 1", false},

		MAKE_COMBOBOX("Blur Direction", "Both",
			{"Off", "Horizontal", "Vertical", "Both"})
	}
},

{"Background",
	{
		MAKE_COMBOBOX("Filter Type", "Flow",
			{"Off", "Shader Offline", "Shader Online", "Flow", NAMED_COLOR_BASE_LIST}),

#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Fancy Background (PRO)", "Off",
			{"Off", "Solid", "Diagonal Lines", "Gradient", "Dot Matrix", "Spider Web",
			 "Checkerboard", "Wire Grid", "Parallelograms", "Wave Lines", "Matrix Rain",
			 "Slash", "Concentric Rectangles", "Perspective Lines", "Pixel Grid", "Starfield",
			 "Random Vertical Lines", "Cross Grid", "Spiral Lines", "Meteors"}),
#else
		MAKE_COMBOBOX("Fancy Background (PRO)", "Off",
			{"Off"}),
#endif
		{"Fancy Background Opacity (0~1)", 0.5f},

		{"Filter Opacity (0~1)", 0.5f},
		{"Filter Shader Offline Path", ""},
		{"Filter Shader Online Name", ""},
		{"Lightness (0~1)", 0.8f},
		{"Hide Filter When No Focus", true},

		MAKE_COMBOBOX("When to Apply Filter", "Menu On",
			{"Always", "Menu On", "Menu Off"}),

		{"Screen Compensation", false},
		{"Screen Compensation Faster", true},
		{"Screen Mode Redraw Client Texture", true},

		MAKE_COMBOBOX("When to Apply Screen Compensation", "Always",
			{"Always", "Menu On", "Menu Off"}),

		{"Screen Compensation Cooldown (ms)", 250U},
	}
},

{
	"Warp UI",
	{
		{"Easing", true},
		{"Easing Speed (0~1)", 0.12f},
		MAKE_COMBOBOX("When", "Always",
			{"Always", "Menu On", "Menu Off"}),

		// ==============================
		// 3D Warp 参数
		// ==============================

		{ "Camera Offset X", 0.0f },   // 平移
		{ "Camera Offset Y", 0.0f },

		{ "Camera Yaw",      0.0f },   // 旋转
		{ "Camera Pitch",    0.0f },
		//{ "Camera Roll",	0.0f},

		{ "Camera Z", 0.0f},           // 透视强度（越大越平）
		{ "Camera Fov", 60.0f},         // 预缩放，防止边缘露黑
		{ "Curve Camera Z Bias", 1.0f},

		{ "Sphere Radius", 600.0f},    // 球体半径（越大曲率越小）

		{ "Flip Y", true},

		// ==============================
		// 视觉效果（Shader）
		// ==============================
		{ "Chroma", 0.008f},           // 边缘色差强度
		{ "Vignette", 0.25f},          // 暗角强度

		// ==============================
		// 行为控制（预留）
		// ==============================
		MAKE_COMBOBOX("Projection",     
			"Sphere (Inside)",
			{"Plane", "Sphere (Inside)", "Sphere (Outside)"})
	}
},

{"GUI Blur",
	{
		MAKE_COMBOBOX("Style",					// 风格
		"Blur (Tinted)",
		{"Off", "Mica", "Acrylic", "Blur", "Blur (Tinted)", "Experimental"}),

		{"Blur Color Alpha (0~1)", 0.3f},
		{"Blur Color", "43;43;43"},

		MAKE_COMBOBOX("Dark Mode", "On",		// 深色模式
			{"Off", "On", "Auto"}),

		{"Not When Power Saving", true},

		{"Hide When No Focus", true},			// 无焦点时隐藏
	}
},

{"HUD Blur",
	{
		MAKE_COMBOBOX("Style", "Blur",
			{"Blur", "Liquid Glass (PRO)"}),

		{"Screen Capture Cooldown (ms)", 10L},
		{"Opacity (0~1)", 1.0f},

		{"Blur Strength", 20.0f},
		{"Blur Taps", 32},
		{"Blur Brightness (0~1)", 0.5f},

#ifdef PROFESSIONAL_VERSION
		{"Dropdown GUI Background (PRO)", true},
#else
		{"Dropdown GUI Background (PRO)", false},
#endif

		{"Liquid Blur", false},
		{"Liquid Corner Roundness Rate", 0.6f},
		{"Liquid Thickness Rate", 0.12f},
		{"Liquid Edge Width Rate", 0.45f},
		{"Liquid Distortion (px)", 10.0f},
		{"Liquid Highlight", 8.f},
		{"Liquid IOR", 1.5f},
		{"Liquid Scatter Size (px)", 1.0f},
		{"Liquid Scatter Directions", 5},
		{"Liquid Scatter Quality", 2.0f},

		{"Liquid Flow Strength", 0.2f},
		{"Liquid Flow Scale", 14.0f},
		{"Liquid Speed", 0.8f},
		{"Liquid Brightness", 0.8f},
	}
},

{"Custom HUD",
	{
		{"Global Scale", 1.0f},
		{"Default Font Size", 30},
		{"Hide HUD When Menu On", true},
		{"Give Way to Mouse", true},
		{"Shell Mover Speed", 10},
		{"Elements", "[]"},

		{"Exhibition", false},
		{"Exhibition Size", 35},

		{"Adjust", false},
		{"Adjust Size", 35},

		{"Vape", false},
		{"Vape Scale", 0.8f},
		MAKE_COMBOBOX("Vape Color", "White",
		{"Flow", NAMED_COLOR_BASE_LIST}),
		{"Vape Follow Arraylist", false},

		{"LiquidBounce", false},
		{"LiquidBounce Scale", 0.8f},
		MAKE_COMBOBOX("LiquidBounce Color", "White",
		{"Flow", NAMED_COLOR_BASE_LIST}),
		{"LiquidBounce Follow Arraylist", false},

		{"SigmaJello", false},
		{"SigmaJello Scale", 0.6f},

		{"Rise", false},
		{"Rise Scale", 0.55f},
		MAKE_COMBOBOX("Rise Color", "Flow",
		{"Flow", "Rainbow", NAMED_COLOR_BASE_LIST}),
#ifdef PROFESSIONAL_VERSION
		{"Rise Edition (PRO)", "Fly Edition"},
#else
		{"Rise Edition (PRO)", ""},
#endif

		{"Jackal", false},
		{"Jackal Scale", 0.4f},
		MAKE_COMBOBOX("Jackal Color", "White",
		{"Flow", NAMED_COLOR_BASE_LIST}),
		{"Jackal Follow Arraylist", false},

		{"Neverlose", false},
		{"Neverlose Scale", 1.0f},
		MAKE_COMBOBOX("Neverlose Color", "White",
		{"Flow", NAMED_COLOR_BASE_LIST}),
	}
},

{"Scoreboard",
	{
		{"X Rate", 0.72f},
		{"Y Rate", 0.12f},
		{"Scale", 1.0f},
		{"Hide When Menu On", true},
		{"Give Way to Mouse", true},

		{"Title", "BED WARS"},
		MAKE_COMBOBOX("Title Color", "Yellow",
			{NAMED_COLOR_BASE_LIST}),

		{"Tail", "www.hypixel.net"},
		MAKE_COMBOBOX("Tail Color", "Yellow",
			{NAMED_COLOR_BASE_LIST}),

		{"Lines (Sep With Semicolon)", ""},

#ifdef PROFESSIONAL_VERSION
		{"Lines Allow Variables (PRO)", true},
#else
		{"Lines Allow Variables (PRO)", false},
#endif

		{"Variable Update Cooldown (ms)", 1000L},

		{"Show Vanilla Values", true},
		MAKE_COMBOBOX("Value Color", "Red",
			{NAMED_COLOR_BASE_LIST}),

		{"Allow Minecraft Color Format", true},
		{"Horizontal Space", 100},

		{"Background", true},
		{"Background Round Corners", false},
		{"Background Roundness (0~1)", 0.2f},
		MAKE_COMBOBOX("Background Color", "Black",
			{"Flow", NAMED_COLOR_BASE_LIST}),
		{"Background Opacity (0~1)", 0.5f},

#ifdef PROFESSIONAL_VERSION
		{"Background Shadow (PRO)", true},
#else
		{"Background Shadow (PRO)", false},
#endif
		{"Background Shadow Opacity (0~1)", 0.5f},
		MAKE_COMBOBOX("Background Shadow Color", "Black",
			{NAMED_COLOR_BASE_LIST}),
		{"Background Shadow Thickness", 20.0f},

		{"Line Gap Rate", 0.75f},

		{"Outline", false},
		MAKE_COMBOBOX("Outline Color", "Flow",
			{"Flow", NAMED_COLOR_BASE_LIST}),
		{"Outline Width", 2.0f},
		{"Outline Opacity (0~1)", 0.8f},
	}
},

{"Hud Editor",
	{
		{"Show Key Names", true},
		{"Show Old Values", false},
		{"Show New Values", true},
		{"Show Status", true},

		{"Show Rectangle", true},
		{"Rectangle Opacity (0~1)", 0.7f},
		
		{"Preview Key", {{"Keybind", {VK_LCONTROL}}}},
		{"Drag Key", {{"Keybind", {VK_MBUTTON}}}},
	}
},

{"Island",
	{
		{"Font Size", 40},
		{"Scale", 1.0f},
		{"Width Addition", 40},
		{"Max Width Rate (0~1)", 0.7f},
		{"Height Addition", 15},
		{"Easing Speed (0~1)", 0.1},
		MAKE_COMBOBOX("Easing Type (PRO)", "Smooth",
			{"Smooth", "Elastic"}),
		{"Elastic Stiffness (0~1)", 0.2f},
		{"Elastic Damping (0~1)", 0.72f},
		{"Elastic Snap Threshold", 0.6f},
		{"Show Brand", true},
		{"Show User", true},
		{"Local User", true},
		{"Show FPS", true},
		{"Show Time", true},
		{"Show Volume", false},
		{"Show Web", true},
		{"Show Game", true},

		{"Brand Icon (PRO)", "wolf.png"},
		{"Brand Name (PRO)", "Jackal"},
		{"Brand Edition", true},
		{"Brand Version", false},
		
		MAKE_COMBOBOX("Show Battery", "Level",
		{"Off", "Icon", "Status", "Level", "Level & Status"}),

		MAKE_COMBOBOX("Show Location", "Off",
			{"Off", "Short", "Details"}),

		{"Show Other", true},

		{"Hide When Idle", false},
		MAKE_COMBOBOX("Idle Persistent Mode", "Off",
			{"Off", "Top", "Bottom"}),
		MAKE_COMBOBOX("Lyrics Persistent Mode", "Bottom",
			{"Off", "Bottom", "Top"}),
		{"Hide While Hold Key", {{"Keybind", {VK_TAB}}}},
		{"Sync Notify Status", true},
		{"Sync Progress Status", true},
		{"Sync Title Status", false},
		{"Sync Actionbar Status", false},
		
		{"Outline Thickness", 3.0f},
		{"Outline Darkness (0~1)", 0.2f},
		{"Round Corners", true},
		{"Roundness", 0.9f},
		{"Background", true},
		{"Background Darkness (0~1)", 0.6f},
		{"Background Opacity (0~1)", 0.75f},

		{"Shadow", true},
		{"Shadow Opacity (0~1)", 0.35f},
		{"Shadow Thickness", 70.0f},
		//{"Show Icon", true},

		MAKE_COMBOBOX("Idle Icon Type", "Normal",
		{"Off", "Character", "Normal"}),

		{"Diversify Notify Icons", true},

		{"Icon Scale", 1.0f},

		MAKE_COMBOBOX("Icon Color", "White",
		{"Flow", NAMED_COLOR_BASE_LIST}),

		{"Give Way to Mouse", true},
		{"Give Way to Mouse Intensity", 0.5f},

		//{"Location Update Cooldown (ms)", 30000L},

		{"Line Height Scale", 1.5f},
		{"Icon Opacity (0~1)", 1.0f},
		{"Text Shadow", true},
		{"Clip Strictly", true},
		{"Fade Duration (ms)", 500L},
		{"Fade Color", true},
#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Transition Type (PRO)", "Right",
			{"Fade", "Right", "Left"}),
#else
		MAKE_COMBOBOX("Transition Type (PRO)", "Fade",
			{"Fade", "Right", "Left"}),
#endif
		{"Transition Speed (0~1)", 0.5f},
		{"Transition Blur", false},
		{"Transition Blur Intensity (0~1)", 0.5f},
		{"Transition Blur Extension", true},
		{"Transition Blur Extension Threshold (0~1)", 0.9f},
		{"Gradient Color", true},
		{"Background Image", false},
		MAKE_COMBOBOX("Background Image Mode", "Custom",
			{"Custom", "Cover (PRO)"}),
		{"Background Image Path", ""},
		{"Background Image Scale", 1.0f},
		{"Background Image Opacity (0~1)", 0.5f},
		{"Background Image Blur", true},
		{"Background Image Blur Intensity (0~1)", 0.4f},
		{"Background Image Moving Speed", 0.5f},

		{"Lyrics Text Color", "255;109;194;255"},
		{"Lyrics Flow Color", false},
		MAKE_COMBOBOX("Lyrics Alignment", "Center",
			{"Center", "Left", "Right"}),
		MAKE_COMBOBOX("Translation Position", "Below",
			{"Below", "Above", "Override"}),
		{"Show Lyrics Translation", true},
		{"Center Main Lyric With Translation", false},
		{"Translation Font Size Rate", 0.8f},
		{"Translation Opacity Rate (0~1)", 0.8f},

#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Translation Source", "Driver (PRO)",
			{"Basic", "Basic+", "Driver (PRO)", "Driver+ (PRO)", "Manual"}),
#else
		MAKE_COMBOBOX("Translation Source", "Basic",
			{"Basic", "Basic+", "Manual"}),
#endif
		{"Translation Gap", 6},
		{"Lyrics Animation Duration (ms)", 500L},
#ifdef PROFESSIONAL_VERSION
		{"Smooth Lyrics Interrupt (PRO)", true},
		MAKE_COMBOBOX("Lyric Per-Char State (PRO)", "Fade",
			{"Off", "Animation", "Tint", "Fade"}),
		{"Lyric Per-Char Update Interval (ms) (PRO)", 500L},
		{"Lyric Per-Char Progress Compensation (PRO)", 1.0f},
		{"Lyric Per-Char Unread Opacity (0~1) (PRO)", 0.25f},
		MAKE_COMBOBOX("Lyric Per-Char Tint Color (PRO)", "Gold",
			{NAMED_COLOR_BASE_LIST}),
		{"Per-Char State Affects Translation (PRO)", false},
#else
		{"Smooth Lyrics Interrupt (PRO)", false},
		MAKE_COMBOBOX("Lyric Per-Char State (PRO)", "Off",
			{"Off" }),
		{"Lyric Per-Char Update Interval (ms) (PRO)", 500L},
		{"Lyric Per-Char Progress Compensation (PRO)", 1.0f},
		{"Lyric Per-Char Unread Opacity (0~1) (PRO)", 0.25f},
		MAKE_COMBOBOX("Lyric Per-Char Tint Color (PRO)", "Gold",
			{NAMED_COLOR_BASE_LIST}),
		{"Per-Char State Affects Translation (PRO)", false},
#endif
		{"Lyrics Effect Duration (ms)", 1000L},
		{"Lyrics Garble", "_"},

		MAKE_COMBOBOX("Lyrics Effect", "Off",
		{"Off", "Garble Slide", "Garble Dissolved", "Unfold"

		, "Sine Slide (PRO)"
		, "Stagger Lift (PRO)"
		, "Center Cascade (PRO)"
		, "Stagger Wave (PRO)"
		, "Scale Cascade (PRO)"
		, "Mirror Cascade (PRO)"
		, "Converge (PRO)"
		, "Soft Reveal (PRO)"
		, "Tilt Drop (PRO)"
		, "Float Rise (PRO)"
		, "Flip In (PRO)"
		}),

		MAKE_COMBOBOX("Lyrics Decorations", "Off",
		{"Off", "Prefix", "Suffix", "Prefix + Suffix"}),

		MAKE_COMBOBOX("Lyrics Decoration Type", "Classic",
		{"Classic", "Slash", "Sharp", "Circle", "Chinese Number", "Chinese Number II"}),

		MAKE_COMBOBOX("Outline Color", "Transparent",
			{"Transparent", NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Background Color", "Black",
			{"Transparent", NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Shadow Color", "Black",
			{NAMED_COLOR_BASE_LIST}),
#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Idle Text Color", "Flow",
			{"Flow", NAMED_COLOR_BASE_LIST}),
#else
		MAKE_COMBOBOX("Idle Text Color", "Flow",
			{"Dark Green", NAMED_COLOR_BASE_LIST}),
#endif

		{"Text Glow (PRO)", true},
		{"Text Glow Radius Rate", 0.2f},
		{"Text Glow Alpha (0~1)", 0.5f},

		{"Notify Max Count", 2U },
		{"Notify Show Title", true },
		{"Notify Progress", true },

		MAKE_COMBOBOX("Notify Progress Color", "Type",
			{ "Type", "Flow", NAMED_COLOR_BASE_LIST }),

		{"Notify Progress Height", 5 },

		MAKE_COMBOBOX("Notify Progress Easing", "Cubic",
			{ "Linear", "Cubic" }),

		{"Notify Success Text Color", "84;255;159"},
		{"Notify Error Text Color", "255;114;86"},
		{"Notify Info Text Color", "200;200;200"},
		{"Notify Warning Text Color", "255;222;173"},

		{"Vibration Frequency", 3.0f},
		{"Vibration Amplitude", 2.0f},
		{"Y Rate", 0.12f}
	}
},

{"Time Display",
	{
		{"Font Size", 50},
		{"X Rate", 0.2f},
		{"Y Rate", 0.8f},
		
#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Style", "Flip",
		{"Classic", "Flip", "Flip + Clock"}),
#else
		MAKE_COMBOBOX("Style", "Classic",
		{"Classic", "Flip", "Flip + Clock"}),
#endif

		{"Flip Duration (ms)", 400.0f},

		{"Online Time", false},
		{"Online Time Update Cooldown (ms)", 60000L},

		MAKE_COMBOBOX("Time Announcement", "Notify",
		 {"Off", "Notify", "Chatter", "WinToast", "Title", "Actionbar"}),

		MAKE_COMBOBOX("Time Announcement Mode", "Half Hour",
		 {"Half Hour", "Hour", "Custom"}),

		{"Time Announcement Custom Rules (Sep With Semicolon)", "**:00;**:20;**:40"},

		MAKE_COMBOBOX("Time Announcement Title Color", "Aqua-Blue",
			{NAMED_COLOR_BASE_LIST}),

		{"Time Announcement Title Font Size", 100},

		{"Time Announcement Highlight", true},

		MAKE_COMBOBOX("Color", "Rainbow",
			{"Flow", NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("New Day Notification", "Title",
		{"Off", "Notify", "Chatter", "WinToast", "Title", "Actionbar"}),
#ifdef PROFESSIONAL_VERSION
		{"New Day Calendar (PRO)", true},
#else
		{"New Day Calendar (PRO)", false},
#endif

		MAKE_COMBOBOX("New Day Title Color", "Flow",
			{"Flow", NAMED_COLOR_BASE_LIST}),

		{"New Day Title Font Size", 300},

		{"Background", false},
		{"Background Round Corners", true},
		{"Background Roundness", 0.3f},
		{"Background Opacity (0~1)", 0.8f},
		{"Background Shadow", true},
		{"Background Shadow Thickness", 20.0f},
		{"Background Shadow Opacity (0~1)", 0.5f},

		MAKE_COMBOBOX("Background Color", "Black",
		{"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Background Shadow Color", "Black",
		{NAMED_COLOR_BASE_LIST}),

#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Tick Sound (PRO)", "Dynamic",
			{"Off", "Always", "Silence", "Dynamic", "Music Stopped"}),
#else
		MAKE_COMBOBOX("Tick Sound (PRO)", "Off",
			{"Off", "Always", "Silence", "Dynamic", "Music Stopped"}),
#endif

		{"Tick Sound Volume", 20},
		{"Tick Sound Silence Threshold", 300.0f},

		MAKE_COMBOBOX("Tick Sound Pitch", "Binary",
			{"Normal", "Binary", "Vary"}),

		MAKE_COMBOBOX("Tick Sound Pan", "Surround",
			{"Normal", "Binary", "Surround"}),

		{"Whiter", true},
		{"Wave Color", true},
		{"Opacity (0~1)", 0.7f},
		{"Transparent", true},
		{"Text Background", false},
		{"Hide When Menu On", true},
		{"Give Way to Mouse", true},
		{"Clock Enabled", false}
	}
},

{"Clock",
	{
		MAKE_COMBOBOX("Hour Color", "Purple",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Minute Color", "Red",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Second Color", "Blue",
			{NAMED_COLOR_BASE_LIST}),

		{"Opacity (0~1)", 0.9f},
		{"Thickness Rate", 1.0f},
		{"Scale", 1.0f},

		MAKE_COMBOBOX("Dial Style", "Detailed",
			{"Off", "Normal", "Detailed", "Dual"}),

		MAKE_COMBOBOX("Dial Color", "Magenta",
			{NAMED_COLOR_BASE_LIST}),

		{"Dial Opacity (0~1)", 0.9f},

		MAKE_COMBOBOX("Number Style", "Normal",
			{"Off", "Normal", "Roman", "Test (PRO)"}),

		{"Number Scale", 1.3f},

		MAKE_COMBOBOX("Number Color", "Magenta",
			{NAMED_COLOR_BASE_LIST}),

		{"Number Opacity (0~1)", 0.9f},

		MAKE_COMBOBOX("Second Movement", "Inertia",
			{"Smooth", "Discrete", "Inertia"}),

		MAKE_COMBOBOX("Outline Style", "Circle",
			{"Off", "Circle"}),

		MAKE_COMBOBOX("Outline Color", "Purple",
			{NAMED_COLOR_BASE_LIST}),

		{"Outline Opacity (0~1)", 0.4f},

		{"Second Enabled", true},

#ifdef PROFESSIONAL_VERSION
		{"Dynamic Dial Opacity Control (PRO)", 0.7f},
		{"Dynamic Number Opacity Control (PRO)", 0.7f},
		{"Shadow (PRO)", true},
		{"Number Glow (PRO)", false},
		{"Number Glow Opacity (0~1)", 0.5f},
		{"Hand Glow (PRO)", false},
		{"Hand Glow Opacity (0~1)", 0.5f},
#else
		{"Dynamic Dial Opacity Control (PRO)", 0.0f},
		{"Dynamic Number Opacity Control (PRO)", 0.0f},
		{"Shadow (PRO)", false},
		{"Number Glow (PRO)", false},
		{"Number Glow Opacity (0~1)", 0.5f},
		{"Hand Glow (PRO)", false},
		{"Hand Glow Opacity (0~1)", 0.5f},
#endif

		{"Hide When Menu On", false},
		{"Give Way to Mouse", true},
		{"Number Rotation", false},

		{"Text Enabled", false},
		{"Text", "AUTOMATIC"},
		{"Text Opacity (0~1)", 0.5f},
		{"Text Scale", 0.6f},
		MAKE_COMBOBOX("Text Color", "Pink",
			{NAMED_COLOR_BASE_LIST}),

		{"X Rate", 0.8f},
		{"Y Rate", 0.1f}
	}
},

{"Notification",
	{
		{"Enabled", true},

		MAKE_COMBOBOX("Override Notify When Hidden", "WinToast",
			{"Off", "WinToast", "MessageBox"}),

			{"MessageBox Duration Coefficient", 0.2f},

			MAKE_COMBOBOX("Style", "Metro",
			{"WinToast", "Metro", "Chatter", "Fancy", "MessageBox"}),

			MAKE_COMBOBOX("Metro Style", "Vape",
			{"Old", "Vape", "SilenceFix", "Naven", "Nexus", "Acid", "Southside", "Nvidia (PRO)", "LiquidBounce NextGen", "Lite"}),

			MAKE_COMBOBOX("Translator", "Off",
				{"Off", "Latency", "Ready"}),

			{"MessageBox Random Position", true},
			{"MessageBox Set as Foreground", true},
			{"Font Size", 35},
			{"Min Width", 200},
			{"Height", 45},
			{"Stay Time (0~1)", 0.3},
			{"Max Length", 120},
			{"Opacity (0~1)", 1.0f},
			{"Give Way to Mouse", true},
			{"Give Way to Mouse Opacity (0~1)", 0.3f},
			{"Horizontal Margin", 80},
			{"Vertical Margin", 200},
			{"Line Gap", 10},

			MAKE_COMBOBOX("Start Position", "Bottom-Right",
			{"Bottom-Right", "Top-Right", "Bottom-Left", "Top-Left"}),

			{"WinToast Attempt to Jump Queue", false},
			{"Anti Spam", true},
			{"Anti Spam Min Similarity (0~1)", 0.97f},

			MAKE_COMBOBOX("Notify Module Toggle", "Always",
				{"Off", "Classic", "Keybind", "Always"}
				),

			{"Notify Font Reload", false},
			{"Notify Texture Load", false},

			MAKE_COMBOBOX("Notify Device Changes", "Audio Device",
			{"Off", "Audio Device", "All"}),

			{"Output Notification", true},
			{"Log Notification", true},
			{"Output Notification Debug String", false},

			{"Prefix Timestamp", true},

#ifdef PROFESSIONAL_VERSION
			MAKE_COMBOBOX("Prefix Style", "Jackal (Pro)",
			{"Off", "Old", "Classic", "Standard", "Simple", "Rise", "Mio", "LiquidBounce", "Jackal (Pro)"}),
#else
			MAKE_COMBOBOX("Prefix Style", "Classic",
			{"Off", "Old", "Classic", "Standard", "Simple", "Rise", "Mio", "LiquidBounce", "Jackal (Pro)"}),
#endif

		{"hidden", true},
	}
},

{"Arraylist",
	{
		MAKE_COMBOBOX("Preset", "Custom",
			{"Custom", "Naven", "Nexus", "Raven", "Rise", "Vape"}),

		{"Hide When Menu On", false},
		{"GUI Integration Performance Mode", true},
		{"Give Way to Mouse", true},
		{"Give Way to Mouse Distance", 80.0f},
		{"Font Size", 36},
		{"Line Gap", 9},

		{"Text Glow (PRO)", true},
		{"Text Glow Radius Rate", 0.2f},
		{"Text Glow Alpha (0~1)", 0.5f},

		{"Side Margin", 12},
		{"Vertical Margin", 60},
		{"Drag X", 0},

		MAKE_COMBOBOX("Global Position", "Screen",
			{"Screen", "Foreground", "PointAt"}),

		MAKE_COMBOBOX("Language", "Follow Global",
		{"Follow Global", "English", "简体中文"}),

		MAKE_COMBOBOX("Horizontal Position", "Right", {"Left", "Right"}),
		MAKE_COMBOBOX("Vertical Position (PRO)", "Top", {"Top", "Bottom", "Half"}),
		MAKE_COMBOBOX("Multi-Monitor Layout Rule", "Selected Monitor",
			{"Selected Monitor", "Outermost Monitor"}),

		{"Side Bar", false},
		MAKE_COMBOBOX("Side Bar Position", "Outter", {"Outter", "Inner"}),
		MAKE_COMBOBOX("Entry Exit Animation", "Normal",
			{"Off", "Normal", "Elastic", "Back"}),
		{"Side Bar Text Gap", 15},
		MAKE_COMBOBOX("Side Bar Style", "Disconnected",
			{"Disconnected", "Continuous"}),

		{"Easing Speed (0~1)", 0.2f},
		{"Removed Item Offset Y", 0.0f},
		{"Opacity Min (0~1)", 0.8f},
		{"Opacity Max (0~1)", 0.88f},
		{"Opacity Period (ms)", 3000L},
		//{"Animation Duration", 2000L},

		{"Show Combat", true},
		{"Show Window", true},
		{"Show Process", true},
		{"Show Registry", true},
		{"Show Control", true},
		{"Show Web", true},
		{"Show Render", true},
		{"Show Misc", true},
		{"Show Drivers", true},
		{"Show Info", true},

		MAKE_COMBOBOX("Info Color", "White-Gray",
			{"Flow", NAMED_COLOR_BASE_LIST}),

		{"Info Gap", 10},
		MAKE_COMBOBOX("Extra Info Style", "Off",
			{"Off", "-", "()", "[]", "<>"}),
		/*	{"Rainbow Modules", true},
#ifdef APP_DEBUG_VERSION
			{"Rainbow Enhance", false},
#else
			{"Rainbow Enhance", true},
#endif*/
			MAKE_COMBOBOX("Text Color",
			"Flow",		// Flow / Rainbow++ 将会使用着色器进行染色
			{	NAMED_COLOR_BASE_LIST,
				"Flow", "Rainbow++",
				"Aurora", "Ocean Breeze", "Peach Bloom", "Mint Dream", "Sunset"
			}
			),

			{"Background", true},
			{"Background Outline", true},
			{"Background Shadow", true},
			{"Background Shadow Opacity (0~1)", 0.5f},
			{"Background Shadow Thickness", 40},
			{"Background Round Corners", false},
			{"Background Roundness", 0.3f},
			{"Background Horizontal Padding", 10},
			MAKE_COMBOBOX("Background Height Mode", "Font Size",
				{"Font Size + Line Gap", "Font Size"}),
			{"Background Opacity Min (0~1)", 0.56f},
			{"Background Opacity Max (0~1)", 0.57f},
			{"Background Opacity Period (ms)", 2000L},

			MAKE_COMBOBOX("Background Color", "Black",
				{"Transparent", NAMED_COLOR_BASE_LIST}),

			MAKE_COMBOBOX("Background Shadow Color", "Black",
				{NAMED_COLOR_BASE_LIST}),

			{"Background Color Darkness (0~1)", 0.8f},

			MAKE_COMBOBOX("Background Outline Color", "Transparent",
				{"Transparent", NAMED_COLOR_BASE_LIST}),

			{"Sort By Length", true},
			{"Use Display Length", true},

		{"hidden", true},
	}
},

{"Ambience",
	{
		MAKE_COMBOBOX("Weather", "Rainy",
			{"Off", "Rainy", "Snowy", "Thundery"}),

#ifdef PROFESSIONAL_VERSION
		{"Weather Cycle (PRO)", true},
#else
		{"Weather Cycle (PRO)", false},
#endif
		{"Weather Cycle Interval Min (s) (PRO)", 600L},
		{"Weather Cycle Interval Max (s) (PRO)", 1200L},
		{"Weather Cycle Include Clear (PRO)", true},
		{"Weather Cycle Clear Chance (0~1) (PRO)", 0.2f},
		{"Weather Cycle Thunder Chance (0~1) (PRO)", 0.35f},
		{"Weather Cycle Snow Chance (0~1) (PRO)", 0.35f},
		{"Lightning Display", true},
		{"Lightning Display Duration (ms)", 5000L},
		{"Lightning Opacity (0~1)", 0.65f},
		MAKE_COMBOBOX("Rain Display Position", "Screen",
			{"Screen", "Foreground", "Background"}),
		MAKE_COMBOBOX("Snow Display Position", "Screen",
			{"Screen", "Foreground", "Background"}),
		{"Rain Amount Scale", 1.0f},
		{"Rain Fall Speed", 1.0f},
		MAKE_COMBOBOX("Rain Preset", "Normal",
			{"Normal", "Midnight", "Blood", "Custom"}),
		{"Rain Angle (rad)", 8.168f},
		{"Rain Angle Jitter (rad)", 0.04f},
		{"Rain Speed Jitter (0~1)", 0.15f},
		{"Rain Increase Speed", 10.0f},
		{"Rain Decrease Speed", 5.0f},
		{"Rain Opacity (0~1)", 0.9f},
		{"Rain Avoid Mouse", false},
		{"Rain Avoid Mouse Distance", 160.0f},
		{"Fog Enabled", false},
		{"Fog Intensity (0~1)", 0.35f},
		{"Rain Sound Volume", 30},
		{"Thunder Sound Volume", 100},

		{"Rain Shape", "/"},
		MAKE_COMBOBOX("Rain Color", "Blue",
			{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Rain Mouse Circle", "Off",
			{"Off", "Hide", "Fade", "Lighten", "Darken"}),
		{"Rain Mouse Circle Radius", 200.0f},

		{"Snow Amount Scale", 1.0f},
		{"Snow Fall Speed", 0.45f},
		{"Snow Angle (rad)", 8.02f},
		{"Snow Angle Jitter (rad)", 0.12f},
		{"Snow Speed Jitter (0~1)", 0.55f},
		{"Snow Increase Speed", 10.0f},
		{"Snow Decrease Speed", 5.0f},
		{"Snow Opacity (0~1)", 0.95f},
		{"Snow Avoid Mouse", false},
		{"Snow Avoid Mouse Distance", 160.0f},
		{"Snow Sound Volume", 20},
		{"Snow Shape", "*"},
		MAKE_COMBOBOX("Snow Color", "White",
			{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Snow Mouse Circle", "Fade",
			{"Off", "Hide", "Fade", "Lighten", "Darken"}),
		{"Snow Mouse Circle Radius", 200.0f},
#ifdef PROFESSIONAL_VERSION
		{"Precipitation Vignette (PRO)", 0.0f},
		{"Window Top Snow Accumulation (PRO)", false},
		{"Window Top Snow Accumulation Rate (PRO)", 1.0f},
		{"Window Top Snow Melt Rate Non-Snow (PRO)", 0.3f},
		{"Window Top Snow Shake Loss Rate (PRO)", 0.06f},
		{"Window Top Snow Max Thickness (PRO)", 6},
#else
		{"Precipitation Vignette (PRO)", 0.0f},
		{"Window Top Snow Accumulation (PRO)", false},
		{"Window Top Snow Accumulation Rate (PRO)", 1.0f},
		{"Window Top Snow Melt Rate Non-Snow (PRO)", 0.3f},
		{"Window Top Snow Shake Loss Rate (PRO)", 0.06f},
		{"Window Top Snow Max Thickness (PRO)", 6},
#endif

		{"Mouse Camera Mode", false},
		{"Mouse Camera X Rate", 1.0f},
		{"Mouse Camera Y Rate", 1.0f},
	}
},

{"Auto Danmaku",
	{
		MAKE_COMBOBOX("File Selection Mode", "Single File",
			{"Single File", "Single File Loop", "Folder Random Select", "Folder Sequential Select", "Folder Loop Select"}),

		{"Path", "danmaku_172423516.xml"},
		{"File Selection Max Attempts", 5},
		{"Recursive Selection in Folder", false},
		{"List Current Index", 0},

		{"File Gap Duration (ms)", 0L},
		{"Correct /n to NewLine", true},
		
		{"Notify Danmaku File Name", true},
		//{"Show Advanced Danmaku", true},
		{"Show Top Danmaku", true},
		{"Show Bottom Danmaku", true},
		{"Show Reverse Danmaku", true},
		{"Horizontal Reverse", false},
		{"Vertical Reverse", false},
		//{"Advanced Danmaku Global Opacity (0~1)", 1.0f},

		MAKE_COMBOBOX("Danmaku Font Size Mode", "Auto",
			{"Fixed", "Auto", "Manual"}),

		MAKE_COMBOBOX("White Danmaku Color", "White",
			{NAMED_COLOR_BASE_LIST}),

		{"White Danmaku Color Frozen", false},

		{"Danmaku Font Size Manual Scale", 1.0f},
		{"Lazy Danmaku Pushing", false},

		{"Hotkey (Next Danmaku File)", {{"Keybind", {VK_LCONTROL, VK_LMENU, '2'}}}},
	}
},

{"Auto Title",
	{
		MAKE_COMBOBOX("Mode", "Periodic",
			{"Periodic", "Random", "Smart"}),

		{"Periodic Interval (ms)", 10000L},
		{"Random Min Interval (ms)", 20000L},
		{"Random Max Interval (ms)", 120000L},
		{"Smart Mode Speed", 1.0f},
	}
},

{"Actionbar",
	{
		{"Module Status Auto Switch", true},

//		{"No Fade Animation", false},
		{"Auto Focus", false},
		{"Check Topmost", true},
		{"Draw Prev Text During Animation", true},
		{"Fixed Text", "NEVER GONNA GIVE YOU UP"},
		{"Hide When Menu On", false},
		{"Y Rate", 0.8f},

		MAKE_COMBOBOX("Text Background", "Simple",
			{"Off", "Simple", "Fancy"}),

		MAKE_COMBOBOX("Text Animation", "Slide (Left)",
		{"Off", "Fade", 
		"Slide (Left)", "Slide (Right)", "Slide (Top)", "Slide (Bottom)", "Enlarge", "Enlarge II", "Shrink", "Shrink II"}),

		{"Text Animation Duration (ms)", 1600L},

		{"Text Base Opacity (0~1)", 1.0f},
		{"Text Duration", 4500L},
		{"Text Font Size", 36},

		MAKE_COMBOBOX("Text Color", "Green",
			{"Flow", NAMED_COLOR_BASE_LIST}),

	}
},

{"Fancy Text",
	{
		{"Async", true},
		{"Hide When Menu On", false},
		{"Module Status Auto Switch", true},

		{"Show Duration (ms)", 3000L},
		{"Scale", 100},

		//{"Debug Output", false},

		{"Fixed Text", "阿诺头顶怎么尖尖的"},

		MAKE_COMBOBOX("Cut Words", "Single",
			{"Single", "Double", "API", "API 2", "Bili Suggestion"}
		),

		{"Uppercase Probability (0~1)", 0.9f},

		MAKE_COMBOBOX("Color", "Colorful",
		{"Flow", NAMED_COLOR_BASE_LIST}
			),

		{"Random Rotation", true},
		{"Random Rotation Start Coefficient", 1.0f},
		{"Random Rotation End Coefficient", 1.0f},

		//{"Fog Intensity", 1.0f},
		{"Fog Enabled", false},
		{"Fog Opacity (0~1)", 0.6f},

		MAKE_COMBOBOX("Fog Color", "Black",
		{"Transparent", NAMED_COLOR_BASE_LIST}),

		{"Parallax Intensity", 0.8f},
		{"Camera Movement", true},
		{"Advanced Transitions (PRO)", true},
		{"Transition Chance (0~1) (PRO)", 0.1f},
		{"Transition Opacity (0~1) (PRO)", 0.4f},
		{"Decorations (PRO)", false},
		{"Decorations Opacity (0~1) (PRO)", 0.15f},
		{"Decorations Chance (0~1) (PRO)", 0.5f},
		MAKE_COMBOBOX("3D Perspective (PRO)", "Off",
			{"Off", "Shader", "Simulation"}),

		{"Background Opacity (0~1) (PRO)", 0.15f},
		MAKE_COMBOBOX("Background (PRO)", "Per Sentence",
			{"Off", "Per Sentence", "Per Song"}),
		{"Fade Out Duration (s)", 10.0f},
		{"Background Change Cooldown (ms)", 2000L},
		{"Opacity Min (0~1)", 0.7f},
		{"Opacity Max (0~1)", 0.9f},
		{"Opacity Period (ms)", 6000L},
	}
},

{"Title",
	{
		{"Module Status Auto Switch", true},
		{"Hide When Menu On", false},
		{"Force Previous Fade Out", true},
		{"Force Exit Speed Boost", 2.0f},

		MAKE_COMBOBOX("Title Text Mode", "Fixed",
			{"Fixed", "List Random Element", "List Loop", "Clipboard Text"}),

		{"Main Title Enabled", true},
		{"Subtitle Enabled", true},

		{"Fixed Subtitle Text", "yee~"},

		{"Fixed Title Text", "JackalClient"},
		{"Title Text List", "你好，陌生人;GRW团队招生了;无论你是跑酷大神;还是生存大师;还是PVP大佬;又或是起床大佬;还是PVP大佬;又或是建筑大佬;还是PVP大佬;又或是红石大佬;还是PVP大佬;还是什么都不知道的小白;还是PVP大佬;还是PVP大佬"},
		{"List Current Index", 0},

		MAKE_COMBOBOX("Title Color", "White",
			{"Flow", NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Subtitle Color", "White",
			{"Flow", NAMED_COLOR_BASE_LIST}),

		{"Title Base Opacity (0~1)", 1.0f},
		{"Title Easing Speed (0~1)", 0.02f},
		{"Subtitle Easing Speed (0~1)", 0.02f},

		MAKE_COMBOBOX("Animation Type (Enter)", "Slide (Bottom)",
			{"Fade", "Slide (Top)", "Slide (Left)", "Slide (Bottom)", "Slide (Right)"}),

		MAKE_COMBOBOX("Animation Type (Exit)", "Slide (Top)",
			{"Fade", "Slide (Top)", "Slide (Left)", "Slide (Bottom)", "Slide (Right)"}),

		{"Animation Slide Fade", true},

		MAKE_COMBOBOX("Title Size", "Auto",
			{"Auto", "Fixed"}),

		{"Auto Title Size Scale", 1.0f},
		{"Check Topmost", true},
		{"Auto Focus", false},
		{"Console Output", true},

		{"Random Rotation", true},
		{"Random Rotation Max Value", 100.0f},

		MAKE_COMBOBOX("Text Stroke", "Shadow",
		{"Off", "Shadow", "Glow"}),

		//{"Text Glow Radius Rate", 0.2f},
		//{"Text Glow Alpha (0~1)", 0.65f},
		{"Text Glow Size Rate", 1.3f},
		{"Text Glow Amount", 5U},

		{"Blur Effect", true},
		{"Blur Strength Max", 20.0f},
		{"Blur Samples Max", 10},

		{"Shake Enabled", true},
		{"Shake Amplitude", 60.0f},
		{"Shake Speed", 2.0f},

		{"Brightness Pulse", true},
		{"Brightness Speed (Hz)", 0.72f},
		{"Brightness Min", 0.66f},
		{"Brightness Max", 1.0f},

		{"Fixed Title Size", 200},
		{"Fixed Subtitle Size", 90},
		{"Title Duration", 5000L},
		{"Title Stay Time (0~1)", 0.5f},
		{"Title Subtitle Line Gap", 30},

		{"Mask Enabled", false},
		{"Mask Fade Speed (0~1)", 0.05f},
		{"Mask Alpha (0~1)", 0.5f},

		{"Debug Gizmos", false},
	}
},

{"Totem",
	{
		{"Brightness (0~1)", 0.5f},
		{"Roll", 0.0f},
		{"Scale", 1.0f},
		{"Speed", 1.0f},
		{"Thickness", 0.05f},
		{"Volume", 50},
		{"Particle Count", 30},
		{"Particle Size", 1.0f},
		{"Particle Speed", 1.3f},
		{"Particle Gravity", 0.006f},
		{"Particle Opacity (0~1)", 1.0f},
		{"Cooldown (ms)", 3000L},

		MAKE_COMBOBOX("Chatter New Advancement", "Only First Time",
		{"Off", "Only First Time", "Always"}),
	}
},

{"Auto Totem",
	{
		{"Gatekeeper Deny", true},
		{"Gatekeeper Deny After Query", true},
		{"AntiClose Defend Success", true},
		{"AntiTaskkill Defend Success", true},
		{"AntiDebug Defend Success", true},
		{"AntiInject Defend Success", true},
		{"AutoMute Triggered", true},
	}
},

{ "Anti Capture",
	{
		{"HUD", false},
		{"Hide When Menu On", false},

		{"Console", true},

		MAKE_COMBOBOX("HUD Alignment", "Center",
			{"Left", "Center", "Right"}),

		{"HUD X Rate", 0.5f},
		{"HUD Y Rate", 0.55f},
		{"HUD Font Size", 30},
		{"HUD Text", "////// Anti Capture Enabled /////"},
		{"HUD Opacity (0~1)", 0.8f},

		MAKE_COMBOBOX("HUD Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),
	}
},

{"Black Capture",
	{
		{"HUD", true},
		{"Hide When Menu On", false},
		{"Console", true},

		MAKE_COMBOBOX("HUD Alignment", "Center",
			{"Left", "Center", "Right"}),

		{"HUD X Rate", 0.5f},
		{"HUD Y Rate", 0.55f},
		{"HUD Font Size", 30},
		{"HUD Text", "///// Black Capture Enabled /////"},
		{"HUD Opacity (0~1)", 0.8f},

		MAKE_COMBOBOX("HUD Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),
	}
},

{"Chat Bar",
	{
		{"Background", true},
		
		MAKE_COMBOBOX("Background Size", "Static",
		{"Static", "Dynamic"}),

		{"Background Round Corners", true},
		{"Background Roundness", 0.5f},
		{"Background Shadow", true},
		{"Background Shadow Thickness", 70.0f},
		{"Background Opacity (0~1)", 0.6f},
		{"Background Shadow Opacity (0~1)", 0.5f},

		{"Hide When Menu On", true},
		{"Give Way to Mouse", true},

		{"Text Opacity (0~1)", 0.99f},
		{"Text Font Size", 30},
		{"Text Margin", 20},
		{"Text Line Gap", 10},
		{"Text Shadow", false},

		{"Auto Stick Bottom", true},
		{"Console Read Tail Lines", 30U},
		{"Max Lines", 128},
		{"Max Allowed Burst Lines", 1024U},

		{"Sync IRC Messages", true},
		{"Sync Live Chatters", true},
		{"Sync Console", false},
		{"Sync Console Update Cooldown (ms)", 500},

		{"Message Inflow Rate (ms)", 50},

		{"Easing Horizontal", true},
		{"Easing Vertical", true},
		{"Easing Speed (0~1)", 0.05f},
		{"Horizontal Fade Duration (ms)", 300},
		
		MAKE_COMBOBOX("Background Color", "Black",
		{"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Background Shadow Color", "Black",
		{NAMED_COLOR_BASE_LIST}),

		{"X Rate", 0.02f},
		{"Y Rate", 0.9f},
		{"Max Width Rate", 0.5f},
		{"Max Height Rate", 0.5f},

		{"Fade Old Messages", true},
		{"Fade Old Messages After (s)", 30L},

	}
},

{ "Session HUD",
	{
		// 基本配置
		{"X Rate", 0.1f},
		{"Y Rate", 0.2f},

		{"Hide When Menu On", false},
		{"Give Way to Mouse", true},

		// 头像配置
		{"Avatar Scale", 1.0f},
		{"Avatar Circle", true},
		{"Avatar Opacity (0~1)", 1.0f},

		{"Width", 300},

		// 背景配置
		{"Background", true},
		{"Background Opacity (0~1)", 0.5f},
		{"Background Round Corners", true},
		{"Background Roundness", 0.6f},
		{"Background Shadow", true},
		{"Background Shadow Thickness", 60.0f},
		{"Background Shadow Opacity (0~1)", 0.6f},

		MAKE_COMBOBOX("Background Color", "Flow",
			{"Transparent", "Flow", NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Background Shadow Color", "Black",
			{"Transparent", "Flow", NAMED_COLOR_BASE_LIST}),

		// 文字配置
		{"Text Font Size", 30},
		MAKE_COMBOBOX("Text Color", "White",
			{"Flow", NAMED_COLOR_BASE_LIST}),

		// 时长设置（比如：已游玩时长）
		{"Time Info", true},
	}
},


{"Music Overlay",
	{
		{"Auto Clean Cache", true},

		MAKE_COMBOBOX("Detect Mode", "Hook",
			{"Basic", "ELOG Parser", "Hook"}),
		MAKE_COMBOBOX("SMTC Policy", "Lag Behind",
			{"Off", "Priority", "Lag Behind"}),
		{"Prefer Unpaused Source", true},

		{"X Rate", 0.1f},
		{"Y Rate", 0.1f},

		{"Easing", true},
		{"Easing Speed (0~1)", 0.05f},
		{"Hide When Menu On", false},

		MAKE_COMBOBOX("Auto Hide", "Paused",
			{"Off", "Paused", "Idle"}),
		{"Temp HUD Duration (ms)", 5000L},

		{"Show Playing Status", true},
		
		{"Show Simple Wave", true},
		{"Simple Wave Bar Width", 10.0f},
		{"Simple Wave Bar Gap", 10.0f},
		{"Simple Wave Height", 70.0f},
		{"Simple Wave Easing Speed (0~1)", 0.05f},
		{"Simple Wave Opacity (0~1)", 0.4f},
		{"Simple Wave Rise Speed", 6.0f},
		{"Simple Wave Fall Speed", 0.5f},
		{"Simple Wave Bar Jitter", 0.65f},

		MAKE_COMBOBOX("Simple Wave Color", "White",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Title", "Now Playing",
		{"Off", "Now Playing", "Music Overlay"}),

		{"Cover Image Scale", 1.0f},
		{"Cover Image Opacity (0~1)", 1.0f},
		{"Cover Image Circle", true},
		{"Cover Image Rotation", true},
		{"Cover Image Rotation Speed", 10.0f},
		MAKE_COMBOBOX("Cover Switch Animation", "Loading",
		{"Loading", "Fade"}),
		{"Cover Background Fade Duration (ms)", 280L},

		MAKE_COMBOBOX("Cover Image ClickGUI Background", "Off",
		{"Off", "Blur", "Normal"}),

		{"Give Way to Mouse", true},

		{"Background", true},
		{"Background Opacity (0~1)", 0.5f},
		{"Background Round Corners", true},
		{"Background Roundness", 0.6f},
		{"Background Shadow", true},
		{"Background Shadow Thickness", 60.0f},
		{"Background Shadow Opacity (0~1)", 0.6f},

		MAKE_COMBOBOX("Background Color", "Flow",
			{"Transparent", "Flow", "Cover", NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Background Shadow Color", "Black",
			{"Transparent", "Flow", NAMED_COLOR_BASE_LIST}),

		{"Text Font Size", 30},
		MAKE_COMBOBOX("Text Color", "White",
			{"Flow", NAMED_COLOR_BASE_LIST}),

		{"Progress Bar", true},
		{"Progress Bar Easing", true},
		{"Progress Bar Easing Speed (0~1)", 0.02f},
		{"Progress Bar Update Cooldown (ms)", 1000L},
		{"Progress Bar Height", 6},
		{"Progress Bar Opacity (0~1)", 0.8f},
		MAKE_COMBOBOX("Progress Bar Color", "White",
			{"Flow", NAMED_COLOR_BASE_LIST}),

		{"Time Info", true},
		{"Time Info Font Size", 25},
		MAKE_COMBOBOX("Time Info Color", "White",
			{NAMED_COLOR_BASE_LIST}),
	}
},

{"Cloud Music",
	{
		{"Start App When Enabled", true},
		{"Delete DLL When Disabled", true},

		{"Custom Directory", ""},
	}
},

{"Better Lyrics",
	{
		{"Async", true},

#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Basic Mode", "Driver (PRO)",
		{"Driver (PRO)", "Hook Render", "OCR"}),
#else
		MAKE_COMBOBOX("Basic Mode", "Hook Render",
		{"Hook Render", "OCR"}),
#endif

		{"Unload DLL When Quit", false},

		//{"Delete Cache", false},
		{"Line Index", 0},

		{"Exclude Non-lyrics Content", true},

		{"Skip If Includes Enabled", true},
		{"Skip If Includes", "<>[]{}%@#\\`"},
		{"Skip If Similarity Greater Than", 0.7f},

		{"Remove Letters", false},
		{"Remove Extra Characters", "=."},

		{"Pause When Menu On", false},

		MAKE_COMBOBOX("Notify Music Change", "Actionbar",
		{"Off", "Actionbar", "Notify", "Chatter", "Title", "WinToast"}),

		MAKE_COMBOBOX("Music Player Preset", "Netease Music",
			{"Netease Music", "Kugou Music", "QQ Music", "Custom"}),

		{"Kugou Use Taskbar Lyrics", true},

		{"Window Title", "桌面歌词"},
		{"Window Class Name", "DesktopLyrics"},

		{"Lyrics Auto Correct", false},
		{"Lyrics Fetch Attempt Cooldown (s)", 10},
		{"Lyrics Correction Min Similarity (0~1)", 0.8f},

		{"X Offset", 0},
		{"Y Offset", 70},

#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Display Mode", "Island",
			{"Title", "Chatter", "Notify", "Actionbar", "WinToast", "Fancy", "Speak", "Mixed", "MessageBox", "Island", "Bar Graph", "Karaoke (PRO)"}),
#else
		MAKE_COMBOBOX("Display Mode", "Island",
			{"Title", "Chatter", "Notify", "Actionbar", "WinToast", "Fancy", "Speak", "Mixed", "MessageBox", "Island", "Bar Graph"}),
#endif

		MAKE_COMBOBOX("Chatter Color", "Rainbow",
		{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Chatter Type", "Top",
		{"Scroll", "Top", "Bottom", "Reverse", "Horizontal", "Vertical", "Random"}),	// 弹幕类型

		MAKE_COMBOBOX("Actionbar Color", "Colorful",
		{NAMED_COLOR_BASE_LIST}),
		
		/*{"Language Type", "chi_sim"},*/
		MAKE_COMBOBOX("Language", "Infer From Music Name",
			{"AI Decide", "Infer From Music Name", "chi_sim", "eng", "jpn", "osd", "Custom"}),

		{"Language Candidates (Sep With Semicolon)", "chi_sim;jpn;eng"},

		{"Custom Language", "chi_sim"},

		{"Capture Cooldown (ms)", 700L},

		MAKE_COMBOBOX("Capture Mode", "PrintWindow",		// 捕获模式
			{"PrintWindow", "BitBlt (Screen)"}),

		MAKE_COMBOBOX("Translation", "Off",
			{"Off", "Chinese", "English", "Japanese"}
			),

		MAKE_COMBOBOX("MessageBox Mode", "Background",
			{"Background", "Foreground"}),

		{"MessageBox Duration Coefficient", 1.0f},
		{"MessageBox Set As Tool Window", false},

		MAKE_COMBOBOX("Bar Graph Lyrics Color", "Blue",
		{NAMED_COLOR_BASE_LIST}),

		{"Bar Graph Lyrics Color Jitter", 0.05f},

		{"Bar Graph Lyrics Font Size", 80},
		{"Bar Graph Lyrics Char Extra Gap", 5},
		{"Bar Graph Lyrics Opacity (0~1)", 0.9f},
	}
},

{"Karaoke",
	{
		MAKE_COMBOBOX("Display Mode", "Double", {"Single", "Double"}),

		{"Font Size", 80},
		{"X Rate", 0.5f},
		{"Y Rate", 0.78f},

		MAKE_COMBOBOX("Read Color", "Flow",
			{"Flow", NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Unread Color", "Purple",
			{"Flow", NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Translation Color", "Pink",
			{"Flow", NAMED_COLOR_BASE_LIST}),
		{"Tint", true},
		{"Hide When Paused", true},
		{"Unread Opacity (0~1)", 0.8f},
		{"Read Opacity (0~1)", 1.0f},

		{"Double Pair Gap", 420.0f},
		{"Double Left Lift (px)", 26.0f},

		MAKE_COMBOBOX("Enter Animation", "Soft Reveal (PRO)",
			{"Off", "Garble Slide", "Garble Dissolved", "Unfold",
			 "Sine Slide (PRO)", "Stagger Lift (PRO)", "Center Cascade (PRO)",
			 "Stagger Wave (PRO)", "Scale Cascade (PRO)", "Mirror Cascade (PRO)",
			 "Converge (PRO)", "Soft Reveal (PRO)", "Tilt Drop (PRO)",
			 "Float Rise (PRO)", "Flip In (PRO)"}),

		MAKE_COMBOBOX("Exit Animation", "Float Rise (PRO)",
			{"Off", "Garble Slide", "Garble Dissolved", "Unfold",
			 "Sine Slide (PRO)", "Stagger Lift (PRO)", "Center Cascade (PRO)",
			 "Stagger Wave (PRO)", "Scale Cascade (PRO)", "Mirror Cascade (PRO)",
			 "Converge (PRO)", "Soft Reveal (PRO)", "Tilt Drop (PRO)",
			 "Float Rise (PRO)", "Flip In (PRO)"}),

		{"Animation Duration (ms)", 700L},

		MAKE_COMBOBOX("Translation Position", "Below",
			{"Below", "Above", "Override"}),
		{"Show Lyrics Translation", true},
		{"Translation Font Size Rate", 0.72f},
		{"Translation Opacity Rate (0~1)", 0.8f},
#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Translation Source", "Driver (PRO)",
			{"Basic", "Basic+", "Driver (PRO)", "Driver+ (PRO)", "Manual"}),
#else
		MAKE_COMBOBOX("Translation Source", "Basic",
			{"Basic", "Basic+", "Manual"}),
#endif
		{"Translation Gap", 8},
	}
},

{"Lyrics Physics",
	{
		MAKE_COMBOBOX("Replace Animation", "Push-Over",
		{"Push-Over", "Drop-Replace", "Wave-Push"}),

		// 通用参数（建议）
		{"Lyric Gravity", 580.0f},                 // 重力像素/秒²
		{"Lyric Bounce Coef (0~1)", 0.88f},         // 反弹系数
		{"Lyric Friction (0~1)", 0.15f},            // 顶端摩擦（水平速度衰减）
		//{"Lyric Max Rise Impulse", 900.0f},         // 柱子突然长高时给字的向上冲量上限
		{"Lyric Scale Pulse (0~1)", 0.15f},          // 音量脉冲引起的缩放幅度
		{"Bar Collision", true},
		{"Bar Collide Height Multiplier", 0.8f},
		//{"Lyric Glow Pulse (0~1)", 0.25f},          // 音量脉冲引起的发光强度（如果你做光效）

		// Push-Over 专属
		{"Push-Over Start X Offset", -120.0f},      // 新字从左侧入场的初始偏移
		{"Push-Over Horizontal Speed", 800.0f},     // 新字水平推进速度
		{"Push-Over Hit Impulse", 170.0f},          // 顶飞旧字的瞬时水平/向上冲量
		{"Push-Over Fadeout Time (s)", 2.0f},      // 旧字被顶飞后淡出时长

		MAKE_COMBOBOX("Push-Over Direction", "Left", {"Left", "Right", "Both"}),

		// Drop-Replace 专属
		{"Drop Start Y Offset", 260.0f},           // 新字从顶端上方出生高度
		{"Drop Soft Landing Coef (0~1)", 0.55f},    // 碰到柱顶时的“软着陆”阻尼
		{"Drop Old Fadeout Time (s)", 0.35f},       // 旧字自由落体后的淡出时长

		// Wave-Push 专属
		{"Wave Speed (bars/sec)", 18.0f},           // 波前推进速度（每秒经过的柱子数）
		{"Wave Width (bars)", 6.0f},                // 波宽：影响同时被触发的列数
		{"Wave Push Impulse", 820.0f},              // 波前推到时对旧字的冲量

		{"Allow Rotation", true},
		{"Rotation Friction (0~1)", 0.15f},
		{"Rotation Bounce Coef (0~1)", 0.35f},

	}
},

{"Tesseract OCR",
	{
		{"Executable Path", ""},
		{"Language", "chi_sim"},
	}
},

{"Watermark",
	{
		{"Size", 80},
		{"Menu Off Alpha", 0.3f},
		{"Menu On Alpha", 0.2f},
		{"Text", "W O R M W A K E R"},
		{"Text Whiteness (0~1)", 0.8f},

		MAKE_COMBOBOX("Text Color", "White",
			{"Flow", NAMED_COLOR_BASE_LIST}),

		{"Opacity Min (0~1)", 0.5f},
		{"Opacity Max (0~1)", 0.5f},
	}
},

{"Blackout Sense",
	{
		MAKE_COMBOBOX("Action", "Shutdown",
			{"Off", "Shutdown", "Custom"}),

		{"Countdown (s)", 240},

		{"Countdown HUD", true},
		{"Countdown HUD X Rate", 0.5f},
		{"Countdown HUD Y Rate", 0.3f},
		{"Countdown HUD Font Size", 30},
		MAKE_COMBOBOX("Countdown HUD Color", "Red",
			{"Flow", NAMED_COLOR_BASE_LIST}),
		{"Countdown HUD Custom Text", ""},

		{"Custom Command", "shutdown -s -t 60"},

		MAKE_COMBOBOX("Notify Mode", "Notify",
			{"Off", "Console Output", "Notify", "Title", "WinToast", "Speak", "Real Chatter"}),
	}
},

{"Power Saving",
	{
		{"Forbid Some Modules", true},
		{"Weak Rendering", true},
		{"Limit FPS", 60L},
	}
},

{"Bright",
	{
		{"Percentage (0~100)", 20},

		MAKE_COMBOBOX("Mode", "Lazy",
			{"Once", "Hotkey", "Lazy", "Keep"}),

		{"Hotkey Brightness-", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_OEM_COMMA}}}},
		{"Hotkey Brightness+", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_OEM_PERIOD}}}},
		{"Hotkey Step (%%)", 5},

		MAKE_COMBOBOX("HUD", "Bottom",
			{"Off", "Bottom", "Bottom Big", "Giant", "Giant 2"}),

		{"HUD Duration (ms)", 3000L},
		{"HUD Giant 2 Bar Color", "gold"},

		{"Keeping Cooldown (ms)", 1000L},
	}
},

{"Gamma",
	{
		{"Alpha", 255},
		{"Set Once", false},
		{"Disable When Quit", true},
	}
},

{"Night",
	{
		{"Mask Alpha Rate", 0.8f},
		MAKE_COMBOBOX("When", "Menu On",
			{"Menu On", "Menu Off", "Always"}),

		{"Hide When No Focus", true},
		MAKE_COMBOBOX("Effect Style", "Top Drop",
			{"Classic", "Fluent Radial", "Fluent Corner Fill", "Fluent Ripple", "Top Drop", "Side Shutter"}),
		MAKE_COMBOBOX("Origin", "Mouse",
			{"Screen Center", "Mouse", "Top Left", "Top Right", "Bottom Left", "Bottom Right"}),
		MAKE_COMBOBOX("Easing", "EaseInOutExpo",
			{"EaseOutCubic", "Linear", "EaseInOutSine", "EaseInOutExpo", "EaseOutBack"}),
		{"Animation Duration (ms)", 1000L},
		{"Feather (px)", 140.0f},
		{"Reverse On Disable", true},
		MAKE_COMBOBOX("Boundary Shape", "Circle",
			{"Circle", "Superellipse"}),
		{"Superellipse Power", 4.0f},
		{"Ripple Strength (0~1)", 0.50f},
		{"Ripple Frequency", 7.2f},
		{"Ripple Speed", 1.65f},
		{"Top Drop Card Count", 10},
		{"Top Drop Wave Amplitude (px)", 36.0f},
		{"Top Drop Wave Cycles", 3.8f},
		{"Top Drop Flow Speed", 0.38f},
		{"Side Shutter Feather (px)", 48.0f},
		{"Side Shutter Overshoot (px)", 28.0f}
	}
},

{"Tint",
	{
		MAKE_COMBOBOX("Mode", "Preset",
			{"Static", "Preset"/*, "Screen"*/}),

		{"(Current Color)", "255;255;255"},
		{"Static Color", "200;210;255"},

		MAKE_COMBOBOX("Preset Color", "Aqua-Pink",
			{NAMED_COLOR_BASE_LIST}),

		{"Screen Capture Cooldown (ms)", 1000L},
		{"Screen Samples", 1024},

		{"Coefficient", 1.0f},
	}
},

{"Stuck",
	{
		MAKE_COMBOBOX("Mode", "Simulation",
			{"Simulation", "Process"}),

		{"Opacity (0~1)", 1.0f},
		{"Auto Disable After Duration", true},
		{"Max Duration (ms)", 10000L},
		{"Auto Disable When Menu On", true},

		MAKE_COMBOBOX("HUD", "Text",
			{"Off", "Text"}),

		{"HUD Text Font Size", 40},
		{"HUD Text", "Blinking... %d ticks"},
		{"HUD Text Opacity (0~1)", 0.8f},

		MAKE_COMBOBOX("HUD Text Color", "Pink",
			{"Flow", NAMED_COLOR_BASE_LIST}),

		{"Process List (Sep With Semicolon)", string("obs64.exe;livehime.exe")},
	}
},

{"Anti AFK",
	{
		{"Mouse Move", true},
		{"Mouse Move Cooldown", 2000L},
		{"Mouse Move Duration", 3000L},
		MAKE_COMBOBOX("Key Movement", "Off",
		{"Off", "WASD", "Arrows"}),
		{"Key Move Cooldown", 8000L},
	}
},

{"Anti Rickroll",
	{
		{"Async", true},
		{"Check Cooldown", 200U},

		MAKE_COMBOBOX("Mode", "Simple",
			{"Simple", "Violence"}),

		{"Notify", true},
		{"Simple Allow Kill Process", false},
	}
},

{"Anti Spy",
	{
		{"Async", true},
		{"Check Cooldown (ms)", 1000U},
		{"Toggle Anti Microphone", false},

		{"Clear Recent File History", true},
		{"Clear Recent Office History", true},
		{"Clear Recent Activity Timeline (PRO)", true},
		{"Clear Run History (PRO)", true},
		{"Clear Explorer Search History (PRO)", true},

		{"Disable Clipboard History", true},

#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Anti Prefetch (PRO)", "Filtered",
			{"Off", "Filtered", "All"}),
#else
		MAKE_COMBOBOX("Anti Prefetch (PRO)", "Off",
			{"Off", "Filtered", "All"}),
#endif

		{"Anti Prefetch Deletion Notify", false},

		{"Anti Prefetch Check Cooldown (ms)", 50000L},
		{"Anti Prefetch Whitelist Processes Enabled", true},
		{"Anti Prefetch Whitelist Processes (Sep With Semicolon)", "JackalClient.exe;loader.exe;Inject.exe;Injector.exe;liquidlauncher.exe;Vape_V4.exe;Vape_Lite.exe;patcher.exe;Kangaroo Patcher.exe;我的世界布吉岛启动器.exe"},
		//{"Anti Prefetch Whitelist Path Enabled", false},
		//{"Anti Prefetch Whitelist Path Prefixes (Sep With Semicolon)", ""},
		{"Anti Prefetch Blacklist Processes Enabled", false},
		{"Anti Prefetch Blacklist Processes (Sep With Semicolon)", ""},
		//{"Anti Prefetch Blacklist Path Enabled", false},
		//{"Anti Prefetch Blacklist Path Prefixes (Sep With Semicolon)", "C:\\Windows\\;C:\\Program Files\\;C:\\Program Files (x86)\\;D:\\Program Files\\;D:\\Program Files (x86)\\"},

		{"Notify", true},
	}
},

{"Anti Microphone",
	{
		{"bind", {{"Keybind", {0}}}},
		{"Async", true},
		{"Check Cooldown (ms)", 1000U},
		MAKE_COMBOBOX("Mode", "Default",
			{"Default", "Hold to Talk", "Hold to Mute"}),
		{"Hold Time Threshold (ms)", 500U},
		{"Hold Key", {{"Keybind", {VK_LCONTROL}}}},
		MAKE_COMBOBOX("HUD", "Text",
			{"Off", "Text", "Texture"}),
		{"Hide HUD When Menu On", false},
		{"HUD X Rate", 0.5f},
		{"HUD Y Rate", 0.6f},
		{"HUD Scale", 1.0f},
		{"HUD Opacity (0~1)", 0.8f},
#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("HUD Animation", "Fade",
			{"Off", "Fade", "Slide (PRO)"}),
#else
		MAKE_COMBOBOX("HUD Animation", "Fade",
			{"Off", "Fade"}),
#endif
		{"HUD Animation Duration (ms)", 200L},
		{"Notify", true},
	}
},

{"Auto Clicker",
	{
		{"CPS Transition Speed", 0.2f},
		{"CPS Fast Stop", true},

		{"Left CPS Min", 7U},
		{"Left CPS Max", 14U},
		{"Left Blatant Mode", false},
	    {"Left Sound", "jclick.wav"},
		{"Right CPS Min", 6U},
		{"Right CPS Max", 11U},
		{"Right Blatant Mode", false},
		{"Right Sound", "nclick.wav"},
		{"Extra Key CPS Min", 8U},
		{"Extra Key CPS Max", 15U},
		{"Extra Key Blatant Mode", false},
		{"Extra Key Sound", "kbhit_2.wav"},

		{"Gap Random Deviation (%%)", 10U},
		{"Click Internal Gap", 5U},

		{"Left Mouse Button Enabled", true},
		{"Right Mouse Button Enabled", true},
		{"Extra Key Enabled", false},

		MAKE_COMBOBOX("Extra Target Key", "Custom",
			{"Left Button",
			 "Right Button",
			 "Middle Button",
			 "Custom"}),

		{"Extra Custom Key Code", 32},

		{"Keep Target Window Active", false},

		/*MAKE_COMBOBOX("Hotkey", "Side Button 1",
			{"Side Button 1",
			 "Side Button 2",
			 "Grave ~",
			 "Q", "R", "Z", "X", "C", "V"
			}),*/

		{"Left Hotkey", {{"Keybind", {VK_XBUTTON2}}}},
		{"Right Hotkey", {{"Keybind", {VK_XBUTTON1}}}},
		{"Extra Key Hotkey", {{"Keybind", {0}}}},

#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Left Trigger Mode", "Assist (PRO)",
		{"Hotkey Toggle", "Hotkey Hold",
			"TargetKey Toggle", "TargetKey Hold",
			"Assist (PRO)",
			}),

		MAKE_COMBOBOX("Right Trigger Mode", "Assist (PRO)",
		{"Hotkey Toggle", "Hotkey Hold",
		"TargetKey Toggle", "TargetKey Hold",
		"Assist (PRO)",
		}),
#else
		MAKE_COMBOBOX("Left Trigger Mode", "Hotkey Hold",
		{"Hotkey Toggle", "Hotkey Hold",
			"TargetKey Toggle", "TargetKey Hold",
			"Assist (PRO)",
			}),

		MAKE_COMBOBOX("Right Trigger Mode", "Hotkey Hold",
		{"Hotkey Toggle", "Hotkey Hold",
		"TargetKey Toggle", "TargetKey Hold",
		"Assist (PRO)",
		}),
#endif

		MAKE_COMBOBOX("Extra Key Trigger Mode", "Hotkey Hold",
		{"Hotkey Toggle", "Hotkey Hold",
		"TargetKey Toggle", "TargetKey Hold",
		}),

		MAKE_COMBOBOX("Click Point Setting", "Manual",
			{"Manual", "Locked", "Shake", "Shake Locked"}),

		{"Click Shake Max Radius", 8},
		{"Pause Shake While Not Moving", true},

		MAKE_COMBOBOX("Click Method", "WMessage",
			{"Simulation", "WMessage", "SendInput"}),

		{"Window Message Cancel Left Up", false},
		{"Window Message Cancel Right Up", false},
		{"Window Message Cancel Extra Up", false},

		{"TargetKey Hold Threshold Time", 700U},
		{"Assist Mode CPS Threshold", 5},
		{"Assist Interrupt Cooldown (ms)", 3000L},

		MAKE_COMBOBOX("Notify Mode", "Notify",
			{"Off", "Chatter", "Notify"}),

		{"Stop When Menu On", true},

		{"Only Trigger While Moving", false},	// 仅在移动时触发
		{"Only Window Center", false},			// 鼠标仅在窗口中心触发
		{"Only Window Center Radius", 100.0},
		{"Only In Minecraft Window", false},
		{"Only When Cursor Hidden", false},

		{"Interrupt Key 1", {{"Keybind", {'E'}}}},
		{"Interrupt Key 2", {{"Keybind", {'T'}}}},
		{"Interrupt Key 3", {{"Keybind", {VK_ESCAPE}}}},
		{"Interrupt Key 4", {{"Keybind", {VK_OEM_2}}}},	// 斜杠和问号 (Command)

	}
},

{"Bridge Assist",
	{
		{"Check Window", true},

		MAKE_COMBOBOX("Trigger Condition", "S & D",
			{"S", "S & A", "S & D"}),

		{"BPS", 2.10f},

		MAKE_COMBOBOX("Mode", "Sneak",
		{"Simple", "Sneak"}),

		{"Sneak Key", {{"Keybind", {VK_LSHIFT}}}},
		{"Place Key", {{"Keybind", {VK_RBUTTON}}}},

		{"Sneak Reshift Gap", 50U},
		{"Right Internal Gap", 10U},
		{"Shift Internal Gap", 100U},
		{"Place Sound", true},
	}
},

{"Color Picker",
	{
		{"Exclude Client", true},
		{"HUD", true},
		{"HUD Font Size", 25},

		MAKE_COMBOBOX("Mode", "Tool",
		{"Instant", "Tool"}),

		MAKE_COMBOBOX("Format", "R,G,B",
			{"R,G,B", "H,S,V", "H,L,S", "HEX", "RGB()", "R,G,B (float)"}),

		{"Copy Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, 'C'}}}},
		{"Copy Hotkey (Inverted Color)", {{"Keybind", {VK_LCONTROL, VK_LMENU, 'I'}}}},
	}
},

{"Hex Viewer",
	{
		MAKE_COMBOBOX("Color Mode", "Simple",
			{"Off", "Simple", "Category", "Step", NAMED_COLOR_BASE_LIST}),

		{"Category Null Color", "30;30;30"},
		{"Category CR Color", "&11"},
		{"Category LF Color", "&10"},
		{"Category Control Color", "&6"},
		{"Category Space Color", "&12"},
		{"Category Punct Color", "&14"},
		{"Category Alpha Color", "&7"},
		{"Category Number Color", "&9"},
		{"Category Other Color", "&13"},

		{"Category Punct Unicode Color (Strict)", "255;80;80"},
		{"Category Punct Unicode Color", "72;118;255"},
		{"Category 2-Byte Unicode Color", "255;110;180"},
		{"Category 3-Byte Unicode Color", "255;110;180"},
		{"Category 4-Byte Unicode Color", "255;110;180"},

		{"Step Color Start", "30;30;30"},
		{"Step Color End", "255;255;255"}
	}
},

{"Pe Parser",
	{
		{"Path", ""},
	}
},

{"Chat Ask",
	{
		{"Async", true},
		{"Remove Markdown Format", true},
	}
},

{"Chat Translate",
	{
		MAKE_COMBOBOX("Dest Language", "Chinese-English",
			{"English", "Chinese", "Chinese-English", "Classic Chinese",
			"Japanese", "French", "German"}),
	}
			},

			{"Chat Restruct",
				{
					MAKE_COMBOBOX("Pattern", "AddSpace",
						{"AddSpace", "Reverse", "Shuffle",
						"ExpandSentence", "Abbreviate", "MachineTranslative",
						"Stammer", "Childlike", "Spoken", "Emojis"
						})
				}
			},

			{"Auto Copy",
				{
					MAKE_COMBOBOX("Source Mode", "Fixed",
						{"Fixed", "File Content", "File Random Line"}),

					{"Fixed Text", "/hub"},
					{"File Path", ""},

					{"Only Update When Holding Ctrl", true},

					{"Include Items With Keywords (Sep With Semicolon)", ""},
					{"Exclude Items With Keywords (Sep With Semicolon)", "{player}"},
					{"Ignore Empty Item", true},

					{"Update Cooldown (ms)", 1000},
					{"Change Cooldown (ms)", 10000},
				}
			},

			{"Clipboard Tweaks",
				{
		/*MAKE_COMBOBOX("Change", "Off",
			{
				"Off",
				"Remove Markdown Format",
				"Remove Numbers",
				"Remove URL",
				"Remove URL Parameters",
				"Upper Case",
				"Lower Case",
				"Annoying Case",
				"Fancy Letters",
				"Add Spaces",
				"Reverse",
				"Shuffle",

			}),*/

		{"Notify", true},
		{"Update Cooldown (ms)", 500L},

		{"Remove Markdown", false},
		{"Remove Numbers", false},
		{"Remove URL", false},
		{"Remove URL Arguments", true},
		{"Taboo Super Filter", false},
#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Filter IP Addresses (PRO)", "Off",
			{"Off", "Strict"}),
#else
		MAKE_COMBOBOX("Filter IP Addresses (PRO)", "Off",
			{"Off"}),
#endif

#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Filter Email (PRO)", "Off",
			{"Off", "On"}),
#else
		MAKE_COMBOBOX("Filter Email (PRO)", "Off",
			{"Off"}),
#endif

		MAKE_COMBOBOX("Character Obfuscation", "Off",
			{"Off", "Normal", "Advanced", "Ultimate"}),
		//{"URL Deep Scan", false},

		MAKE_COMBOBOX("Chinese Conversion", "Off",
			{"Off", "Traditional", "Simplified", "Japanese"}),
		{"Second Round Chinese Simplification (PRO)", false},

		MAKE_COMBOBOX("Letter Changes", "Off",
		{"Off", "Upper Case", "Lower Case", "Annoying Case", "Fancy Letters"}),

		/*MAKE_COMBOBOX("Text Shaper", "Off",
		 {"Add Spaces", "Cut Line"}),*/
		
		MAKE_COMBOBOX("Add Spaces Mode", "Off",
		{"Off", "Single", "Double", "Pair", "Wave", "Smaller Random", "Bigger Random"}),

		MAKE_COMBOBOX("Cut Line Mode", "Off",
		{"Off", "Punctuation", "Fixed Length", "Random Length",
		"Wave Left"
		//, "Wave Center"
}),

		{"Cut Line Extra Tail", "喵"},
		{"Cut Line Fixed Length", 12},
		{"Cut Line Random Length Min", 5},
		{"Cut Line Random Length Max", 16},

		MAKE_COMBOBOX("Punctuation Changes", "Off",
		{"Off", "Remove", "To English", "To Chinese", "Random"}),

		MAKE_COMBOBOX("Prefix Mode (PRO)", "Off",
			{"Off", "Custom", "Random Normal", "Random Chinese", "Random Japanese"}),
		MAKE_COMBOBOX("Suffix Mode (PRO)", "Off",
			{"Off", "Custom", "Random Normal", "Random Chinese", "Random Japanese"}),

#ifdef PROFESSIONAL_VERSION
		{"Prefix Custom (Sep With Semicolon)", ""},
		{"Suffix Custom (Sep With Semicolon)", " | WᴜʀꜱᴛCʟɪᴇɴᴛ; | ᴠᴀᴘᴇᴠ₄; - 𝕁𝔸ℂ𝕂𝔸𝕃; | 𝘼𝘓𝙄𝘌𝙉; - 𝐉𝐚𝐜𝐤𝐚𝐥𝐏𝐫𝐨; | 𝕽𝖎𝖘𝖊𝕮𝖑𝖎𝖊𝖓𝖙; | 𝙼𝚒𝚘; | 𝒮ℯ𝓇ℯ𝒾𝓃; ' 𝐑𝐚𝐯𝐞𝐧𝐁𝟒; | 𝗦𝗜𝗚𝗠𝗔; - 𝘕𝘰𝘷𝘰𝘭𝘪𝘯𝘦; / 𝓐𝓭𝓳𝓾𝓼𝓽"},
#else
		{"Prefix Custom (Sep With Semicolon)", ""},
		{"Suffix Custom (Sep With Semicolon)", ""},
#endif
		{"Prefix Random Length Rate", 1.0f},
		{"Suffix Random Length Rate", 1.0f},

		MAKE_COMBOBOX("Invisible Obfuscation (PRO)", "Off",
			{"Off", "Average", "Random"}),

		{"AI Transformation", false},
		{"AI Transformation Prompt", "请将下面的文本每个字符间加一个点后原样输出，不要添加任何的前缀后缀以及说明文字："},

		{"Encryptor", false},

		/*{"Tip URL", true},
		{"Tip Social Numbers", true},*/
	}
},

{"Chest Stealer",
	{
		{"Async", true},

		MAKE_COMBOBOX("Trigger Mode", "Hotkey",
			{"Instant", "Right Mouse Button", "Hotkey"}),

		{"Trigger Hotkey", {{"Keybind", {'B'}}}},
		
		MAKE_COMBOBOX("Trigger Hotkey Interrupt", "Close Container",
			{"Off", "Stop", "Close Container"}),

		{"Interrupt Key 1", {{"Keybind", {'E'}}}},
		{"Interrupt Key 2", {{"Keybind", {VK_ESCAPE}}}},

		MAKE_COMBOBOX("HUD", "Off",
			{"Off", "Basic"}),

		{"HUD Font Size", 30},

		MAKE_COMBOBOX("HUD Target Slot Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Mouse Easing Movement", "EaseInOutSine",
			{"Off", "Linear", "EaseInOutSine", "EaseInOutExpo", "EaseInOutBack"}),

		{"Mouse Easing Duration (ms)", 50L},

		MAKE_COMBOBOX("Notify Mode", "Notify",
			{"Off", "Notify", "Chatter", "Title"}),

		MAKE_COMBOBOX("Slot Selector", "No Empty Detect",
			{"All", "No Empty Detect"}),

		{"Slot No Empty Single Channel Threshold", 1000},

		MAKE_COMBOBOX("Slot Order", "Random",
			{"Snake", "Reverse Snake", "Sequential", "Reverse", "Random"}),

		MAKE_COMBOBOX("Item Operation", "Steal",
			{"Steal", "Drop", "Drag Steal"}),

		MAKE_COMBOBOX("Coordinate Mode", "Semi-Auto",
			{"Semi-Auto", "Manual"}),

		MAKE_COMBOBOX("Container Type", "Small Chest",
			{"Small Chest", "Large Chest", "Hopper", "Dispenser"}),

		{"Slot Size", 52},

		{"Semi-Auto Y Offset Slots (Small Chest)", 3.12f},
		{"Semi-Auto Y Offset Slots (Large Chest)", 4.60f},
		{"Semi-Auto Y Offset Slots (Hopper)", 2.00f},
		{"Semi-Auto Y Offset Slots (Dispenser)", 4.10f},

		{"Manual X Offset (Small Chest)", -240},
		{"Manual X Offset (Large Chest)", -240},
		{"Manual X Offset (Hopper)", -132},
		{"Manual X Offset (Dispenser)", -78},

		{"Manual Y Offset (Small Chest)", -198},
		{"Manual Y Offset (Large Chest)", -278},
		{"Manual Y Offset (Hopper)", -141},
		{"Manual Y Offset (Dispenser)", -198},

		{"Slot Internal Random Offset", true},

		{"Click Internal Gap (ms)", 40L},
		{"Key Internal Gap 1 (ms)", 40L},
		{"Key Internal Gap 2 (ms)", 40L},

		{"Start Delay Min (ms)", 100},
		{"Start Delay Max (ms)", 200},
		{"Operate Delay Min (ms)", 150},
		{"Operate Delay Max (ms)", 250},
		{"End Delay Min (ms)", 100},
		{"End Delay Max (ms)", 200},
		{"Auto Close", true},
		{"Not Trigger While Moving", true},
		{"Minecraft Window Check", true},
		{"Auto Close Key", {{"Keybind", {'E'}}}},
		{"Drop Items Key", {{"Keybind", {VK_LCONTROL, 'Q'}}}},
	}
},

{"Mouse Teleport",
	{
		{"Edge Teleport", true},
		{"Teleport Sound", true},
		{"Sound Path", "teleport.wav"},
		{"Sound Volume", 80},
	}
},

{"Mouse Watcher",
	{
		MAKE_COMBOBOX("Movement Check", "Ignore",
			{"Ignore", "Warn", "Warn & Restore", "Restore"}),

		MAKE_COMBOBOX("Movement Check Mode", "Simple",
			{"Simple", "Strict"}),

		{"Hide HUD When Menu On", true},

		MAKE_COMBOBOX("HUD", "Fancy",
			{"Off", "Simple", "Fancy"}),

		MAKE_COMBOBOX("HUD Color", "White",
			{NAMED_COLOR_BASE_LIST}),

		{"HUD Font Size", 20},
		{"HUD Line Gap", 5},
		{"HUD X Rate", 0.01f},
		{"HUD Y Rate", 0.44f},

		{"Sample Cooldown", 10U},
		{"Acceleration Threshold", 800.0f},
		{"Strict Check Threshold", 10},
	}
},

{"Mouse Disabler",
	{
		{"Allow Move", false},
		{"ALLOW NO KEYBIND", false},
	}
},

{"B Hop",
	{
		{"Only In Game", true},

		{"Basic Tap Cooldown (ms)", 500L},
		{"Repeat Times", 3L},
		{"Repeat Interval (ms)", 50L},

		{"Jump Custom Key Hold Interval (ms)", 100L},
		{"Trigger Key", {{"Keybind", {VK_SPACE}}}},

		MAKE_COMBOBOX("Jump Key", "Wheel Down",
		{"Wheel Down", "Wheel Up", "Custom"}),

		MAKE_COMBOBOX("Trigger Mode", "Hold",
		{"Hold", "Toggle"}),

		{"Jump Custom Key", {{"Keybind", {VK_LMENU}}}},
	}
},

{"Snap Tap",
	{
		{"A & D", true},
		{"W & S", true},
		{"Left & Right Arrows", true},
		{"Up & Down Arrows", true},
		{"Custom Keys", false},
		{"Custom Key Pairs (e.g. Z&X;J&K)", ""},
	}
},

{"Toggle Key",
	{
		{"Minecraft Window Check", false},
		{"Left Mouse Button", false},
		{"Right Mouse Button", false},
		{"A, W, S, D", false},
		{"A, W, S, D Opposite Stop", true},
		{"Alpha Keys", false},
		{"Num Keys", false},
		{"Left Modifier Keys", false},
		{"Arrow Keys", false},
		{"Arrow Keys Opposite Stop", true},
		{"Additional Custom Keys (Code Sep with Semicolon)", ""}
	}
},

{"Caps Guard",
	{

		MAKE_COMBOBOX("Caps Lock Operation", "Disable",
			{"Ignore", "Disable", "Enable"}),

		MAKE_COMBOBOX("Caps Lock When", "Always",
			{"Always", "Chinese Input Method", "Non-chinese Input Method"}),
	}
},

{"Typewriter",
	{
		{"HUD", true},
		{"HUD Font Size", 45},
		
		MAKE_COMBOBOX("HUD Progress Style", "Bottom Bar", 
		{"Off", "Bottom Bar", "Mouse Percentage", "Rainbow Giant"}),

		{"HUD Window Highlight", true},
		{"Hide HUD When Menu On", true},

		{"Keep Disabling IME", true},

		{"Focus Window", true},
		
		{"Init/Stop Hotkey", {{"Keybind", {VK_LMENU, '1'}}}},
		{"Pause/Resume Hotkey", {{"Keybind", {VK_LMENU, '2'}}}},

		MAKE_COMBOBOX("Source", "Clipboard",
			{"Fixed", "Clipboard", "File", "AI Answer"}),

		{"Clipboard Tweaks Module Text Processor", false},
		{"Accelerate Space Typing", true},

		MAKE_COMBOBOX("Display On Send", "Off",
		{"Off", "Notify", "Chatter", "Title", "Actionbar", "Fancy", "WinToast"}),

		MAKE_COMBOBOX("Display Chatter Color", "Rainbow",
		{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Display Chatter Type", "Top",
		{"Scroll", "Top", "Bottom", "Reverse", "Horizontal", "Vertical", "Random"}),	// 弹幕类型

		{"Source Fixed", "An apple a day keeps the doctor away."},
		{"Source File Path", ""},
		{"Source AI Ask", "Please tell me Li Bai's famous poem in Chinese."},

		MAKE_COMBOBOX("Timing Mode", "Smart",	// 节奏模式
			{"Instant", "Fixed", "Smart"}),

		{"Timer", 1.0f},						// 变速
		{"Fixed Delay", 100U},
		{"Key Internal Gap", 10U},

		MAKE_COMBOBOX("Auto Send", "Off",		// 自动发送
			{"Off", "Sentence", "Sentence (Entire)", "Fixed Length", "Clock"}),

		MAKE_COMBOBOX("Auto Send Key", "Ctrl + Enter",
			{"Enter", "Ctrl + Enter"}),
		MAKE_COMBOBOX("Auto Send Method", "Simulation",
			{"Simulation", "WMessage"}),

		{"Send Fixed Length", 10U},
		{"Send Period (ms)", 1000U},

	}
},

{"Typing Practice",
	{
		{"Enabled", false},
		{"Text Scale", 1.0f},
		MAKE_COMBOBOX("Completed Color", "Blue",
			{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Remaining Color", "White",
			{NAMED_COLOR_BASE_LIST}),
		MAKE_COMBOBOX("Next Color", "Yellow",
			{NAMED_COLOR_BASE_LIST}),
		{"Show Box", true},
		{"Text Space", 0.0f},
		{"Box Easing", true},
		{"Box Easing Speed (0~1)", 0.1f},
		{"Allow Wrong Input", false},
	}
},

{"Key Disabler",
	{
		//{"Key Locker Mode (Press End to end)", false}
		MAKE_COMBOBOX("Mode", "Locker (Press End to escape)",
			{"Win", "LCtrl, Win, LAlt", "Locker (Press End to escape)",
			"Ctrl, Win, Alt", "A,W,S,D,Space,Shift"}),
	}
},

{"Key Mapper",
	{
		{"Enabled", false},
		MAKE_COMBOBOX("Mode", "Virtual",
			{"Simulation", "Virtual"}),
		{"Custom Mappings", "[]"},
		{"System Mappings (READONLY)", "[]"}
	}
},

{"Key Logger",
	{
		{"Console Output", true},
		{"Log Output", true}
	}
},

{"Key Reaction",
	{
		//{"Auto Release List (Sep With Semicolon)"},
		{"Auto Release F22 When WeChat Running", true},

		{"Key Reaction Data Enabled", true},
		{"Key Reaction Data JSON Array", "[]"},

		MAKE_COMBOBOX("Key Notify Mode", "Notify",
			{"Off", "Notify", "Chatter", "Title"}),
	}
},

{"Typing Effects",
	{
		{"Not As Debuggee", true},

		MAKE_COMBOBOX("IME Indicator", "Temp",
			{"Off", "Temp", "Always"}),

		MAKE_COMBOBOX("IME Indicator Style", "1",
		    {"1", "2", "3", "4", "5"}),

		{"IME Indicator Size", 50},
		{"IME Indicator Temp Duration (ms)", 3000L},

		MAKE_COMBOBOX("Caret Indicator", "Temp",
			{"Off", "Temp", "Always"}),

		{"Caret Indicator Temp Duration (ms)", 5000L},

		MAKE_COMBOBOX("Caret Indicator Style", "Capture",
			{"Arrow", "Box", "Crosshair", "Capture"}),

		{"Caret Indicator Size", 40},
#ifdef PROFESSIONAL_VERSION
		{"Caret Indicator Scale Pulse (PRO)", true},
#else
		{"Caret Indicator Scale Pulse (PRO)", false},
#endif
		{"Caret Indicator Capture Scale", 4.0f},
		{"Caret Indicator Capture Rotation Speed", 4.0f},
		MAKE_COMBOBOX("Caret Indicator Capture Style", "Render",
			{"Texture", "Render"}),
#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Caret Indicator Capture Selection (PRO)", "Scale",
			{"Off", "Scale", "Ends"}),
#else
		MAKE_COMBOBOX("Caret Indicator Capture Selection (PRO)", "Off",
			{"Off", "Scale", "Ends"}),
#endif
		MAKE_COMBOBOX("Caret Indicator Capture Rotation Mode (PRO)", "Auto",
			{"BackForth", "Forth", "Back", "Auto"}),

		MAKE_COMBOBOX("Caret Particles", "Moving",
			{"Off", "Moving", "Continuous"}),

		{"Caret Particles Amount", 1.0f},
		{"Caret Particles Color Jitter", 0.2f},

		MAKE_COMBOBOX("Caret Particles Color", "Rainbow",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Caret Indicator Arrow Style", "Up",
			{"Up", "Down", "Up & Down"}),

		{"Caret Indicator Opacity (0~1)", 0.8f},

		MAKE_COMBOBOX("Caret Indicator Color", "Rainbow",
			{"Flow", NAMED_COLOR_BASE_LIST}),
#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Caret Indicator IME Color Highlight (PRO)", "1",
			{"Off", "1", "2"}),
#else
		MAKE_COMBOBOX("Caret Indicator IME Color Highlight (PRO)", "Off",
			{"Off", "1", "2"}),
#endif

		{"Caret Update Cooldown (ms)", 500L},
		{"Caret Easing", true},
		{"Caret Easing Speed (0~1)", 0.05f},

		MAKE_COMBOBOX("Area Indicator", "Off",
			{"Off", "Temp", "Always"}),

		{"Area Indicator Easing", true},
		{"Area Indicator Easing Speed (0~1)", 0.2f},

		MAKE_COMBOBOX("Area Indicator Color", "Red",
		{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Selected Text Indicator", "Off",
			{"Off", "Temp", "Always"}),

		MAKE_COMBOBOX("Selected Text Indicator Mode", "Translation",
			{"Raw", "Translation"}),

		{"Selected Text Indicator Translation Exclude Characters", "^#{}<>\\/*|"},
		{"Selected Text Indicator Translation Max Length", 300},

		MAKE_COMBOBOX("Selected Text Indicator Color", "Blue",
		{"Flow", NAMED_COLOR_BASE_LIST}),
		
		{"Selected Text Indicator Opacity (0~1)", 0.75f},
		{"Selected Text Indicator Size", 30},
		{"Selected Text Indicator Temp Duration (ms)", 5000L},
		
#ifdef PROFESSIONAL_VERSION
		MAKE_COMBOBOX("Key Particle Effect (PRO)", "Fall",
			{"Off", "Throw", "Fall"}),
#else
		MAKE_COMBOBOX("Key Particle Effect (PRO)", "Off",
			{"Off"}),
#endif
		{"Key Particle Max Speed", 600.0f},
		{"Key Particle Gravity", 800.0f},
		{"Key Particle Bounce (0~1)", 0.6f},
		{"Key Particle Font Size", 45},
		{"Key Particle Opacity (0~1)", 0.5f},
		MAKE_COMBOBOX("Key Particle Color", "Flow",
			{"Flow", NAMED_COLOR_BASE_LIST}),
		{"Key Particle Show Control Keys", true},
	}
},

{"Key Sound",
	{
		MAKE_COMBOBOX("Alloc Mode", "All",
			{"All", "Keyboard All", "Mouse All", "Category", "Custom"}),

		MAKE_COMBOBOX("Detect Mode", "Raw Input",
			{"Raw Input", "GetKeyState"}),

		MAKE_COMBOBOX("Folder Sound Selection", "Folder Random Select",
			{"Folder Random Select", "Folder Map Select"}),

		{"Recursive Selection in Folder", true},

		MAKE_COMBOBOX("Debug Notification", "Off",
			{"Off", "File Path", "Key Name"}),

		{"All Mode Sound", ""},
		{"Keyboard All Mode Sound", ""},
		{"Mouse All Mode Sound", ""},

		{"Category Left Click Sound", ""},
		{"Category Right Click Sound", ""},
		{"Category Other Mouse Sound", ""},
		{"Category Control Sound", ""},
		{"Category Letter Sound", ""},
		{"Category Num Sound", ""},
		{"Category Punct Sound", ""},
		{"Category Esc Sound", ""},
		{"Category Enter Sound", ""},
		{"Category Back Sound", ""},
		{"Category Arrow Sound", ""},
		{"Category Lock Sound", ""},
		{"Category FN Sound", ""},
		{"Category Space Sound", ""},
		{"Category Other Keyboard Sound", ""},

		{"Custom Mode Config File", "config/keyCustomSounds.ini"},
	}
},

{"Macro Recorder",
	{
		//{"Mouse Pos Sample Rate (Hz)", 20},

		MAKE_COMBOBOX("Output Format", "Jackal Macro",
			{"Jackal Macro", "Jackal Batch"}),

		{"First Perspective Mouse Offset", false},
		{"First Perspective Mouse Offset Scale X", 5.0f},
		{"First Perspective Mouse Offset Scale Y", 1.0f},

		MAKE_COMBOBOX("Recording HUD", "Off",
			{"Off", "Rec", "Red Rectangle"}),

		{"Recording HUD Font Size", 50},
		{"Recording HUD X Rate", 0.05f},
		{"Recording HUD Y Rate", 0.12f},

		{"Notify File Path", true},
		{"Notify Actions (Chatter)", false},
		{"Notify Mouse Pos (Chatter)", false},
		{"Record Window Assertions", false},

		{"bind (Enable)", {{"Keybind", {0}}}},
		{"bind (Disable)", {{"Keybind", {0}}}},
	}
},

{"Macro Player",
	{
		{"Start Delay (ms)", 3000L},
		{"Close Menu", true},
		{"Macro Path", ""},
		{"Notify", true},
		{"Actionbar Display Key Press", true},
		{"Actionbar Display Mouse Move", true},
		{"Actionbar Display Mouse Wheel", true},
		{"Perform Window Assertions", true},
		{"Reset Keyboard When Disable", true},
		{"Auto Loop", false},

		MAKE_COMBOBOX("Playing HUD", "Off",
			{"Off", "Replay", "Blue Rectangle"}),

		{"Playing HUD Font Size", 50},
		{"Playing HUD X Rate", 0.05f},
		{"Playing HUD Y Rate", 0.12f},	

		{"Adjust Offset Step (ms)", 50L},
		{"adjust offset (Earlier)", {{"Keybind", {VK_LCONTROL, VK_UP}}}},
		{"adjust offset (Later)", {{"Keybind", {VK_LCONTROL, VK_DOWN}}}},

		{"bind (Enable)", {{"Keybind", {0}}}},
		{"bind (Disable)", {{"Keybind", {0}}}},
	}
},

{"Quick IME",
	{
		MAKE_COMBOBOX("Basic Mode", "Tool",
			{"Once", "Tool"}),

		MAKE_COMBOBOX("Toggle Mode", "Single",
			{"Next", "Single"}),

		{"Toggle Hotkey", {{"Keybind", {VK_CAPITAL}}}},
	}
},

{"No IME",
	{
		{"Restore", true}
	}
},

{"Meme Trigger",
	{
		/*MAKE_COMBOBOX("Hotkey", "RCtrl + A~Z",
			{"RCtrl + A~Z",
			"RShift + A~Z",
			"RCtrl/RShift + A~Z",
			"RCtrl + RShift + A~Z"}),

		{"Disable ForceTopmost", true},
		{"Minimize Client", true},*/

		{"no_signal", {{"Keybind", {0}}}},
		{"genshin_impact", {{"Keybind", {0}}}},
		{"what", {{"Keybind", {0}}}},

		{"hyw", {{"Keybind", {0}}}},
		{"zmq", {{"Keybind", {0}}}},
		{"hyw Folder Path", ""},
		{"zmq Folder Path", ""},

		{"Notify", false},
		{"Disable Client Other HUD", true}
	}
},

{"Volume",
	{
		/*MAKE_COMBOBOX("Vol+", "Ctrl+Shift+Up",
			{"Off", "Ctrl+Shift+Up", "Ctrl+Alt+Plus"}),

		MAKE_COMBOBOX("Vol-", "Ctrl+Shift+Down",
			{"Off", "Ctrl+Shift+Down", "Ctrl+Alt+Minus"}),

		MAKE_COMBOBOX("Mute", "Ctrl+Shift+M",
			{"Off", "Ctrl+Shift+M", "Ctrl+Alt+0"}),
		*/

		MAKE_COMBOBOX("Auto Mute", "Off",
			{"Off", "Once On Launch", "Output Device Changed", "Output Device Name Keyword When Changed"}
			),

		{"Auto Mute Output Device Name Keyword (Include)", ""},
		{"Auto Mute Output Device Name Keyword (Exclude)", "耳机"},

		MAKE_COMBOBOX("Auto Mute Notify", "Title",
			{"Off", "Title", "Notify", "Chatter", "Actionbar", "WinToast"}),

		{"Vol+", {{"Keybind", {VK_LCONTROL, VK_LSHIFT, VK_UP}}}},
		{"Vol-", {{"Keybind", {VK_LCONTROL, VK_LSHIFT, VK_DOWN}}}},
		{"Mute", {{"Keybind", {VK_LCONTROL, VK_LSHIFT, 'M'}}}},

		{"Hide HUD When Menu On", false},

		MAKE_COMBOBOX("Volume Mode", "System",
					{"System", "Process"}),

		MAKE_COMBOBOX("System Volume HUD", "Temp",
					{"Off", "Temp", "Always"}),

		MAKE_COMBOBOX("System Volume HUD Style", "Bottom",
					{"Bottom", "Bottom Big", "Giant", "Rainbow Giant"}),

		MAKE_COMBOBOX("Process Volume HUD", "Temp",
					{"Off", "Temp", "Always"}),

		MAKE_COMBOBOX("Process Volume HUD Style", "Bottom",
					{"Bottom", "Giant", "Rainbow Giant"}),

		MAKE_COMBOBOX("Notify Type", "Off",
			{"Off", "Console Output", "Notify"}),

		MAKE_COMBOBOX("Wheel System Volume Adjust", "Mouse On Taskbar",
			{"Off", "LAlt", "RAlt", "Mouse On Taskbar"}),

		MAKE_COMBOBOX("Wheel Process Volume Adjust", "Mouse On Caption",
			{"Off", "LAlt", "RAlt", "Mouse On Caption"}),

		{"Process Volume Smart ID Infer", true},

		{"Wheel Detect Only If Cursor Visible", true},

		{"Wheel Volume Step", 5U},

		{"Step (%%)", 5U},

		{"Temp HUD Duration (ms)", 3000L},
		{"Temp HUD Animation Duration (ms)", 300L},

		{"Limit System Volume", false},
		{"System Volume Min", 1},
		{"System Volume Max", 50},
	}
},

{"Music",
	{
		{"Filename", "FunkyStars.mp3"},

		MAKE_COMBOBOX("When", "Menu On",
		{"Menu On", "Menu Off", "Always"}),

		MAKE_COMBOBOX("Style", "Normal",
		{"Normal", "Damaged"}),

		{"MCI Mp3 Volume", 100},
	}
},

{"Speaker",
	{
		{"Async", true},
		{"Notify Error", true},
		{"Not As Debuggee", true},

		MAKE_COMBOBOX("Method", "SAPI",
			{"SAPI"}),

		MAKE_COMBOBOX("Voice", "Default",
		{"Default", "Auto", "Custom"}),

		{"Custom Voice Name", "Microsoft Huihui Desktop - Chinese (Simplified)"},

		MAKE_COMBOBOX("Rate", "Default",
		{"Default", "Auto", "Custom"}),

		{"Auto Rate Coefficient", 1.0f},

		{"Custom Rate", 0},

		{"Volume", 80},

		MAKE_COMBOBOX("Pitch", "Default",
		{"Default", "Auto", "Custom"}),

		{"Custom Pitch", 0},

		{"Japanese Transformation", true},

		MAKE_COMBOBOX("Multiple Text Arrangement", "Queue",
			{"Off", "Queue", "Available"}),

		MAKE_COMBOBOX("Spoken Text Mode", "Fixed",
			{"Fixed", "List Random Element", "List Loop", "Clipboard Text"}),

		{"Fixed Spoken Text", "Hello World 你好，世界！"},
		{"Spoken Text List", "你的钢门比较松弛;但是呢,你的痔疮又弥补了这一部分;如果做痔疮手术,把痔疮切除的话;可能就会显得你的钢门就比较大;可能会有一些漏液漏气的情况;现在最好的办法就是;在做痔疮手术的同时;给你做一个钢门紧缩术"},
		{"List Current Index", 0},
	}
},

{"Auto Speak",
	{
		MAKE_COMBOBOX("Main Mode", "Off",
			{"Off", "Periodic", "Random", "Smart"}),

		{"Periodic Interval (ms)", 10000L},
		{"Random Min Interval (ms)", 20000L},
		{"Random Max Interval (ms)", 120000L},
		{"Smart Mode Gap (ms)", 1000L},

		MAKE_COMBOBOX("Translator (Except Main Mode)", "Off",
						{"Off", "Chinese", "English", "Exchange"}),

		{"Speak Actionbar", false},
		{"Speak Title", true},
		{"Speak Subtitle", false},
		{"Speak Chatter", false},
		{"Speak Dialog (Auto Detect)", false},
		{"Dialog Text Max Speak Length", 100U},
		{"Skip Speaking Dialog Text Same As Previous", true},
	},
},

{"Mute",
	{
		MAKE_COMBOBOX("Mode", "Status",
			{"Status", "Amount", "Both"}),

		{"Amount Mode Restore Volume", true}
	},
},

{ "Mixer",
{
	MAKE_COMBOBOX("Bar Direction", "Down",
		{"Right","Up","Left","Down"}),

	MAKE_COMBOBOX("HUD Mode", "Temp",
		{"Always", "Temp"}),

	{"Temp HUD Duration (ms)", 3000L},
	{"Temp HUD Animation Duration (ms)", 300L},

	{"Bar Max Height", 500},

	MAKE_COMBOBOX("Bar Color", "White", {"Flow", NAMED_COLOR_BASE_LIST}),
	{"Bar Opacity (0~1)", 0.35f},

	{"Hide When Menu On", true},

	{"Easing", true},
	{"Easing Speed (0~1)", 0.1f},

	{"Text Font Size", 28},
	MAKE_COMBOBOX("Text Color", "Colorful", {NAMED_COLOR_BASE_LIST}),

	MAKE_COMBOBOX("Label Format", "Process Name",
		{"PID", "Process Name", "Both"}),

	// 辅助配置（强烈建议加）
	{"Bar Thickness", 80},              // 每条的厚度（类似 barWidth）
	{"Bar Gap", 100},
	{"Show Only Volume > 0", true},     // 近似“发声”
	{"Max Items", 10},                  // 太多会挤爆
	{"Refresh Interval (ms)", 500.0f},         // COM 枚举节流（m秒）
	{"Base X Rate", 0.5f},
	{"Base Y Rate", 0.05f},
	{"X Offset", 0.0f},
	{"Y Offset", 0.0f},
} },

{"Audio Isolation",
	{
		{"Process Name (Empty For Any)", "JackalClient.exe"},
		{"Process Id (Zero For Any)", 0},

		{"Set Highlight Process Volume", false},
		{"Highlight Process Volume (%%)", 80},
		{"Other Process Volume (%%)", 10},

		{"Fade Duration (ms)", 1000L},
	}
},

{"SMTC",
	{
		{"Auto Disable On Init Failure", true},
		{"Update Cooldown (ms)", 700L},
		{"Fetch Cover", true},
		{"Max Cover Cache", 8},
		{"Max Cover Bytes (KB)", 2048},
	}
},

{"Active",
	{
		{"Cooldown", 0},
	}
},

#define GUI_STYLE_PRESETS \
		MAKE_COMBOBOX("Style Preset", "Default",	\
		   { "Default", "Old", "Modern", "Vape", "LiquidBounce", "LiquidBounce NextGen", "Raven", "Meteor", "Future", "Opai" })

{"GUI Styler",
	{
		GUI_STYLE_PRESETS,
	}
},

{"Force Topmost",
	{
		{"Cooldown", 25},
		{"Use SW_RESTORE", false},
		{"Not While Hidden", true},
		{"Not While Screenshot", true},
		{"Not While Using IME", true},
		{"bind", {{"Keybind", {VK_RCONTROL, 'F'}}}}
	}
},

{"Triggers",
	{
		{"Async", true},
		{"Default Check Cooldown (s)", 1.0f},
		{"Default Trigger Cooldown (s)", 60.0f},
		MAKE_COMBOBOX("Default Trigger Attribute", "Cooldown",
			{"Default", "Cooldown", "Once", "Once Remove"}),
		MAKE_COMBOBOX("Notify Mode", "Notify",
			{"Off", "Notify", "Chatter", "Title", "WinToast"})
	}
},

{"Taskbar Icon",
	{
		{"FORBID TASKBAR ICON", false},
	}
},

	{"Screen Capture",
		{
			MAKE_COMBOBOX("Backend", "GDI",
				{"GDI", "DXGI"}),

			MAKE_COMBOBOX("Exclude Client", "Keep",
				{"Off", "Slow", "Keep"}),
		}
	},

	{"Ascii Art Convert",
		{
			MAKE_COMBOBOX("Image Source", "Clipboard",
				{"Fixed", "Clipboard"}),

			{"Fixed Image Path", ""},
			{"Max Columns", 80},
			{"Max Rows", 40},
			{"Scale", 1.0f},
			{"Brightness (0~1)", 0.5f},
			{"Contrast", 1.0f},
#ifdef PROFESSIONAL_VERSION
			MAKE_COMBOBOX("Character Set", "Braille (PRO)",
				{"Normal", "Letter", "Number", "Braille (PRO)", "Kana (PRO)", "Custom (PRO)"}),
#else
			MAKE_COMBOBOX("Character Set", "Normal",
				{"Normal", "Letter", "Number", "Braille (PRO)", "Kana (PRO)", "Custom (PRO)"}),
#endif
			{"Custom Set", ""},
			{"Color Merge Threshold (0~1)", 0.01f},
			MAKE_COMBOBOX("Output Mode", "Console Output",
				{"Console Output", "File Output"}),
			{"File Output Path", ""},
			MAKE_COMBOBOX("Output Format", "Normal",
				{"Normal", "Metasploit Banner"}),
		}
	},

	{"Screenshot",
		{
			MAKE_COMBOBOX("Mode", "Tool",
				{"Instant", "Tool"}),

			{"Close Vanilla Snipping Tool", true},
			{"Notify Close", true},

			{"Preview Brightness (0~1)", 0.6f},
			{"HUD Font Size", 35},

			MAKE_COMBOBOX("Save Image", "Default",
				{"Off", "Default", "Desktop", "Custom", "Dialog"}),

			{"Save Image Custom Path", "D:\\"},

			MAKE_COMBOBOX("Copy Image", "DIB",
				{"Off", "DIB", /*"DIBV5",*/ "PNG+DIB"}),

			{"Enable Ascii Art", false},

			MAKE_COMBOBOX("Extract Text (PRO)", "Off",
				{"Off", "Silent Copy", "Console Output"}),

			{"Extract Text Language (PRO)", "chi_sim"},

			{"Countdown", false},
			{"Countdown Duration (ms)", 3000L},

			MAKE_COMBOBOX("Exclude Client", "Shift Key",
				{"Off", "Shift Key", "Always"}),

			// 已经帮你绑好了
			{"bind", {{"Keybind", {VK_LCONTROL, VK_SNAPSHOT}}}},
		}
	},

	{"Audio Visualizer",
		{
			{"Capture Cooldown (ms)", 50L},
			{"Menu On Alpha", 1.0f},
			{"Menu Off Alpha", 1.0f},

			{"Global HUD Pulse Effects", false},
			{"Global HUD Pulse Effects Intensity (0~1)", 0.5f},

			{"Enable Better Lyrics Module", false},

			MAKE_COMBOBOX("Visualizer Mode", "Bar Graph",
			{"Off", "Bar Graph", "Line Wave", "Circle Spectrum"}),
			
			MAKE_COMBOBOX("Bar Graph Style", "Normal",
			{"Normal", "Pixel"}),

			{"Bar Pixel Gap", 5},
			{"Bar Width", 25L},
			{"Bar Horizontal Gap", 2},
			{"Bar Graph Max Width Rate", 1.0f},
			{"Bar Graph Horizontal Start Rate (0~1)", 0.0f},
			{"Bar Max Height", 250L},
			{"Bar Opacity (0~1)", 0.3f},
			{"Bar Easing Speed (0~1)", 0.15f},
			{"Bar Y Rate", 1.0f},
			MAKE_COMBOBOX("Bar Direction", "Up", {"Up", "Down", "Both"}),

			MAKE_COMBOBOX("Bar Color", "White",
				{"Flow", NAMED_COLOR_BASE_LIST}),

			MAKE_COMBOBOX("Bar Color (Top)", "Same",
				{"Same", NAMED_COLOR_BASE_LIST}),
				
			// 线形波形参数
			{"Line Y Rate", 0.8f},
			{"Line Thickness", 3L},
			{"Line Amplitude", 300.0f},
			MAKE_COMBOBOX("Line Color", "Blue", {NAMED_COLOR_BASE_LIST}),
			{"Line Opacity (0~1)", 0.6f},
			MAKE_COMBOBOX("Line Direction", "Up", {"Up", "Down", "Both"}),

			// 环形频谱参数
			{"Circle Radius", 250L},
			{"Circle Thickness", 5L},
			{"Circle Scale", 1.8f},
			MAKE_COMBOBOX("Circle Color", "Gold", {NAMED_COLOR_BASE_LIST}),
			{"Circle Opacity (0~1)", 0.8f},
		}
	},

	{"Time Manager",
		{
			{"Async", true},

			MAKE_COMBOBOX("Mode", "Offset Toggle",
				{"Freeze", "Set Once", "Offset Once", "Offset Toggle", "Online Sync Once", "Online Sync Keep",
				 "Set Accelerated", "Offset Accelerated", "Accelerated"
				}),

			MAKE_COMBOBOX("Sync Method (Disabling Freeze)", "Memory",
				{"Off", "Memory", "Web"}),

			MAKE_COMBOBOX("Sync Method (Disabling Set)", "Memory",
				{"Off", "Memory", "Web"}),

			MAKE_COMBOBOX("Sync Method (Disabling Offset)", "Config",
				{"Off", "Config", "Web"}),

			{"Online Sync Cooldown (ms)", 30000L},
			{"Acceleration Speed", 1.0f},

			{"Set Year", 2025},
			{"Set Month", 2},
			{"Set Day", 28},
			{"Set Hour", 12},
			{"Set Minute", 0},
			{"Set Second", 0},

			{"Offset Year", 0},
			{"Offset Month", 0},
			{"Offset Day", 0},
			{"Offset Hour", 12},
			{"Offset Minute", 0},
			{"Offset Second", 0},
		}
	},

	{"Console",
		{
			{"Non-client Rendering Policy", false},
			MAKE_COMBOBOX("Module Toggle Mode", "Visibility",
			{"Visibility", "Existence"}),

			{"Random Title", true},
			{"Disable Quick Edit", true},
			{"Disable Insert Mode", false},
			{"Disable Mouse Input", true},
			{"Disable Close", true},

			MAKE_COMBOBOX("Selection Block Action", "Auto Esc",
				{"Off", "Warn", "Auto Esc"}),

			{"Enable Titlebar Right Click Menu", false},
			{"Hide Console", false},
			{"Font Size", 18},

			MAKE_COMBOBOX("Advanced Background Style",
				"Off",
				{"Off", "Mica", "Acrylic", "Test"}),

			MAKE_COMBOBOX("Dark Mode", "On",
				{"Off", "On", "Auto"}),

			{"Round Corner", true},

			MAKE_COMBOBOX("Font Name", "Consolas",
				{"新宋体", "宋体", "黑体", "楷体", "等线",
				"Candara", "Consolas", "Lucida Console", "Segoe UI", "Tahoma"}),

			{"Border Color", ""},
			{"Caption Color", ""},
			{"Caption Text Color", ""},

			{"bind", {{"Keybind", {VK_RCONTROL, 'C'}}}}
		}
	},

			{"Developer",
				{
			{"AI Context", false},
			{"Speak", true},
			{"Web Request", false},
			{"Fancy Text", false},
			{"Query IP Location", true},
			{"Quake Warning", true},
			{"Execute OCR", false},
			{"Better Lyrics Lines", false},
			{"Better Lyrics AI Decision", true},
			{"Better Lyrics AI Decide Prompt", false},
			{"Better Lyrics Result", false},
			{"RunWormwakeCommand", true},
			{"Chinese Translation", false},
			{"system2", true},
			{"Level System", false},
			{"Level System Profiles HUD", false},
			{"Live Gift Check", false},
			{"Live Chatter Time Diff", false},
			{"MC Log Lines", false},
			{"MC Send Chat", false},
			{"MC AI Speak Detect Result", true},
			{"Verification", false},
			{"Neverlose GUI", false},
			{"Music Overlay Ratio", false},
			{"Music Overlay", true},
			{"Cloud Music", true},
			{"Disable MC Check", false},
			{"Disable Auto Update", false},
			{"Realm Connection", true},
			{"Force Live Stream AI (Context) Prompt", false},
			{"Not Responding Fix", true},
			{"Download Manager", false},
			{"Disable IRC Log Message", false},
			{"ApiHz Error Debug Output", false},
			{"File Manager Highlight Debug", true},
			{"Live Telemetry", false},
			{"Live Telemetry X Rate", 0.5f},
			{"Live Telemetry Y Rate", 0.9f},
			{"Live Telemetry Opacity (0~1)", 0.5f},

			{"Debug Break Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_SUBTRACT}}}}
		}
	},

	{"Quick Command",
		{
			{"Async", true},

			{"Single Instance", true},

			MAKE_COMBOBOX("Input Method", "Input Box",
				{"Input Box", "Chat Box"/*, "Island"*/}),

			{"Trigger Hotkey", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_OEM_3}}}}
		}
	},

	{"Shell",
		{
#ifdef PROFESSIONAL_VERSION
			MAKE_COMBOBOX("Theme", "Jackal Pro",
				{"Default", "Jackal Pro", "Cmd", "PowerShell", "VS2022 Dev PowerShell", "Metasploit", "Kali Linux"}),
#else
			MAKE_COMBOBOX("Theme", "Metasploit",
				{"Default", "Jackal Pro", "Cmd", "PowerShell", "VS2022 Dev PowerShell", "Metasploit", "Kali Linux"}),
#endif

			MAKE_COMBOBOX("Jackal Pro Subtheme", "Simple",
				{"Simple", "Kali Hacker Box", "Classic Kali", "PowerLevel Arrow", "Predator Minimal", "Cyber Neon Frame", "Military Protocol", "Default"}),

			{"Exclusive Mode", false},
			{"Input Prompt Color", "yellow"},

			MAKE_COMBOBOX("Input Prompt", "$>",
				{
					">",
					"$>",
					"$",
					">>>",
					"JC >",
					"Custom",
				}),

			{"Command Completion", true},
			{"Command Highlighter", true},
			{"Command Hints", true},

			{"Save Command History", true},

			{"Allow Terminate Shell Thread", false},
			{"Close Menu", true},
			{"Custom Input Prompt", ">>>"},
			{"Input Color", "white"},
			{"Command Max Length", 65535L},
			{"Echo Command", false},
			{"Using Builtin Variables", true},
			{"Using Environment Variables", true},

			{"Max History Length", 500},

			MAKE_COMBOBOX("Batch File Error Level", "Only Exception",
				{"Ignore", "Only Exception", "All Errors"}),

			{"Batch File Execution Notify", true},

			MAKE_COMBOBOX("Chatter Color", "White",
				{NAMED_COLOR_BASE_LIST}),
			MAKE_COMBOBOX("Title Color", "Rainbow",
				{NAMED_COLOR_BASE_LIST}),

			/*{"Title Font Size", 400},*/
			{"bind", {{"Keybind", {VK_RCONTROL, 'S'}}}}
		}
	},

	{"Hidden",
		{
			{"Hide Console When Hidden", true},
			{"Auto Hide Client When GUI Closed", false},
			{"Disable Client Keybind When Hidden", true},
			{"Disable Tray Tip", false},
		}
	},

	{"Restart",
		{
			{"Run As User", false},
			{"Generate Arguments", true},
			{"bind", {{"Keybind", {VK_RCONTROL, 'R'}}}}
		}
	},

	{"Exit",
		{
			{"bind", {{"Keybind", {VK_RCONTROL, VK_DELETE}}}}
		}
	},

	{"Remote Kill HR",
		{
			{"Hidden Cmd", false},
			{"Exclude Myself", true},
			{"Exclude Low PID", true},
		}
	},

	{"Shader",
		{
			MAKE_COMBOBOX("Apply Area", "Client Only",
				{"Client Only", "Screen"}),

			MAKE_COMBOBOX("Style", "bloom",
				{"bloom",
				 "bloom_time",
				"blur",
				//"cross_hatching",
				"cross_stitching",
				"dispersion",
				"dream_vision",
				"flash_shake",
				//"mvp",
				"old",
				"pixelizer_time",
				"shadow_glitch",
				"sobel"}),

			{"Blur Strength", 2.0f},
			{"Blur Samples", 5},

			{"Bloom Samples", 1.0f},
			{"Bloom Quality", 0.2f},
			{"Bloom Intensity", 0.3f},
			//{"Bloom Threshold", 0.4f},

			{"Screen Mode Update Cooldown", 33U},
			{"Screen Mode Redraw Client Texture", true},
			{"Screen Compensation Faster", true},

			{"Flow Text Theme Period (s)", 300L},
			{"Flow Text Speed", 1.0f},
			{"Flow Text Scale", 6.0f},
			{"Flow Text Noise Amount", 0.6f},
			{"Flow Text Brightness", 1.2f},
			{"Flow Text Depth", 0.6f},
		}
	},

	{"Vape",
		{
			MAKE_COMBOBOX("Color", "White",		// Rainbow++ 将会使用着色器进行染色
			{	/*"White",
				"Rainbow",*/
				"Flow",
				NAMED_COLOR_BASE_LIST,
				"Rainbow++"
			}),

			{"Easing Speed (0~1)", 0.1f},

			MAKE_COMBOBOX("Logo", "Vape",
				{"Vape", "LiquidBounce", "Neverlose", "Jackal", "Custom"}),

			{"Give Way to Mouse", true},
			{"Custom Logo Path", ""},

			{"X Offset", 0},
			{"Y Offset", 0},
			{"Scale", 1.0f},
			{"Opacity (0~1)", 1.0f},
		}
	},

	{"Close AV",
		{
			{"Huorong", true},
			{"360", true},
		}
	},

	{"Kill 360",
		{
			MAKE_COMBOBOX("360 Process Detection Method", "Directory",
				{"Fixed List", "Directory"}),
		}
	},

	{"Kill 360 Test",
		{
			MAKE_COMBOBOX("360 Process Detection Method", "Directory",
				{"Fixed List", "Directory"}),

			MAKE_COMBOBOX("Operation When Max Process Attempts Reached", "Next Process",
				{"Next Process", "Stop"}),

			MAKE_COMBOBOX("Filter Architecture", "x64",
				{"Both", "x64", "x86"}),

			{"Max Process Attempts", 1},
		}
	},

	{"Kill AV",
		{
			MAKE_COMBOBOX("Method", "Driver",
				{"Normal", "Driver"}),
		}
	},

	{ "Kill Malware",
		{
			MAKE_COMBOBOX("Method", "Normal",
				{"Normal", "Driver"}),
		}
	},

	{ "Kill Everyone",
		{
			MAKE_COMBOBOX("Method", "Normal",
				{"Normal", "Driver"}),
		}
	},

	{"Protection",
		{
			{"Block Child Processes", false},
		}
	},

	/*{"Taskbar Pin",
		{
			{"Verb Method (< Win 10)", false}
		}
	}*/
},
},

{"Config",

	{
					MAKE_COMBOBOX("Freeze Client", "Off",
						{"Off", "Always", "When Hidden"}),

					//{"Async Update", false},
					{"Single Instance",	true},
					{"Disable Log", false},
					{"Simplified Log", false},
					{"Max Log History Files", 8L},
					{"Auto Toggle As Prev Run", true},
					{"Save Module Toggle Data", true},
					{"Only Save Profile Difference", true},
					{"Remove Outdated Module Options", true},
					{"Save Data More Frequently", false},
					{"Backup Records Cache", true},
					{"Backup Profile Config", true},
					{"Load Profile Backup On Main Read Failure", true},
					{"Notify When Profile Backup Loaded", true},
					{"Profile Backup Cooldown (ms)", 90000U},

					/*{"Disable DPI Scaling", true},*/
					{"Use Client Exception Filter", false},
					{"C++ Exception Catcher", true},
					{"Exception Filter Minidump Enabled", false},
					{"Exception Filter Export Crash Log", true},
					{"Exception Filter Open Crash Log", true},

					{"Restart Recovery Enabled", true},
					{"Restart Manager Arguments", "--restarting"},
					{"Recovery Callback Enabled", true},
					{"Recovery Ping Interval (ms)", 5000U},
					{"Recovery Notify Last Session", true},
					{"Recovery Marker File", "restart_recovery.marker"},

					//{"Exception Filter Auto Load Symbol", true},
					MAKE_COMBOBOX("Display Client on Which Monitor", "#0",
						{"#0"}),
					MAKE_COMBOBOX("Client Display Region", "Single Monitor",
						{"Single Monitor", "Switch To Active Monitor", "Per-Monitor Windows"}),
					{"Client Executable Name Force Check", true},
					{"Init Client Registry On Start", true},

					//#ifdef APP_DEBUG_VERSION
					//			{"Block Unsafe Modules", true},
					//#else
					//			{"Block Unsafe Modules", true},
					//#endif
					MAKE_COMBOBOX("Work-in-progress Modules", "Deny",
						{"Deny", "Shift + Click", "Allow"}),

					MAKE_COMBOBOX("Unsafe Modules", "Shift + Click",
						{"Deny", "Shift + Click", "Allow"}),

					MAKE_COMBOBOX("Driver-Used Modules", "Shift + Click",
						{"Deny", "Shift + Click", "Allow"}),

					{"Force Driver Modules Admin", false},

					{"Check Module Privileges Before Turning On", true},
					MAKE_COMBOBOX("Elevate and Retry Admin Modules", "Off",
						{"Off", "Standard", "UAC Bypass"}),

					{"Disallow WMI ProcessKill", true},
					{"Disallow Driver ProcessKill (Suggest)", true},
					{"Lock Module Toggle", false},
					{"Exclude GUI Keys From Keybinds", true},
					{"Float Options Digits", 3U},
					{"String Preview Length", 16U},
					{"Options Cross Toggle Close", false},
					
					{"Check Client Privileges Status", false},
					
					MAKE_COMBOBOX("Check Module Toggle", "Async",
						{"Off", "Sync", "Async"}),

					{"Check Module Toggle Cooldown (ms)", 10000U},
					{"Check Module Toggle When Startup", false},
					{"Check Client Privileges Cooldown (ms)", 20000U},
					{"Output Configs Saving", false},
					//{"Notify Audio Device Change", true},

					{"Process List Update Async Mode", true},
					{"Process List Update Freq (Hz)", 15.0f},

					{"Top Level Windows Update Cooldown (ms)", 5000U},
					{"Top Level Windows Update Async Mode", true},

					MAKE_COMBOBOX("Max FPS", "120",
						{"30", "60", "90", "120", "240", "Unlimited"}),
					{"V-Sync", false},

					{"Limit FPS When Minecraft Focused", true},
					{"Minecraft Focus Max FPS", 60L},
					{"Lightweight Draw When Minecraft Focused", false},

					MAKE_COMBOBOX("File Size Unit Base", "1000",
							{"1000", "1024"}),

					MAKE_COMBOBOX("Mouse Wheel Detector", "Window",
						{"Window", "Raw Input"}),

					//{"Support High DPI", false},
					{"Always Run", true},
					{"Always Admin", false},

					MAKE_COMBOBOX("Always Admin Mode", "Normal",
						{"Normal", "Bypass"}),

					MAKE_COMBOBOX("GetProcAddress", "Default",
					{"Default", "Manual"}),

					{"Volume", 100L},
					{"Auto Unload Front Extra Font Chars Max Count", 3000L},
					/*{"Esc Key Exit", false},*/
				},
			},

{
"GUI",

	{
	   /*GUI_STYLE_PRESETS,*/

	   MAKE_COMBOBOX("Window Display Mode", "Undecorated",
		   {"Undecorated", "Borderless"}),

#ifdef PROFESSIONAL_VERSION
	   MAKE_COMBOBOX("ClickGUI Style (Restart to Apply)", "Dropdown",
		   {"Dropdown", 
		   "Neverlose (PRO)", 
		   "Imgui"}),
#else
	   MAKE_COMBOBOX("ClickGUI Style (Restart to Apply)", "Dropdown",
		   {"Dropdown",
		   "Imgui"}),
#endif

	   {"Close When No Focus", false},
	   {"Better Topmost", true},
	   {"Better Topmost Enable Experimental Features", false},
	   {"Better Topmost Detect WorkerW", true},
	   {"Better Topmost Detect Progman", false},
	   {"Better Topmost Detect ShellDLL_DefView", false},
	   {"Better Topmost LivePreview PassThrough", false},
	   {"Better Topmost ExplorerWinUI PassThrough", false},
	   {"Better Topmost ExplorerWinUI Auto Close Menu", false},
	   {"Better Topmost Same Monitor Only", true},
	   {"Better Topmost Debug Output", false},
	   {"Force LivePreview Topmost", false},
	   {"Disable DPI Scaling", false},
	   {"Black Screen Problem Fix", true},

	   MAKE_COMBOBOX("Not Responding Problem Fix", "Null Message",
		   {"Off", "Null Message", "Auto Focus"}),

	   {"Anti Aliasing", false},
	   {"Anti Aliasing Intensity (0~1)", 1.0f},

	   MAKE_COMBOBOX("Sliders", "Always",
			{"Always", "Some", "Off"}),
	   {"Slider Only Editing", true},
	   {"Slider Release Cooldown (ms)", 120L},
	   
	   MAKE_COMBOBOX("Change Focus Before Open GUI", "FocusWindow",
			{"Off", "Simulated Click", "FocusWindow"}),

		{"Change Focus Simulated Click Gap Min (ms)", 30L},
		{"Change Focus Simulated Click Gap Max (ms)", 50L},

	   {"Menu Auto Focus When Open", true},
	   {"Menu Cancel Focus In Minecraft", true},

	   {"Opacity (0~1)", 1.0f},
	   {"Round Corners", false},
	   {"Round Corners of Boolean Box", true},

	   MAKE_COMBOBOX("Shadow Rendering Method", "New",
		   {"Old", "Outdated", "New"}),

	   MAKE_COMBOBOX("Text Shadow Mode", "Fade",
		   {"Disabled", "Fade", "Dark", "Black"}),

	   {"Text Shadow Fade Opacity (0~1)", 0.3f},
	   
	   MAKE_COMBOBOX("Tab Theme Color Mode", "Single",
		   {"Single", "Rainbow", "Flow"}),

	   {"Outline", false},
	   {"Display Module Option Default Value", true},
	   {"Highlight Modified Options", true},

	   MAKE_COMBOBOX("Module Option Style", "Integration",
		   {"Old", "Integration"}),

	   {"Module Option Integration Item Max Count", 10},
	   {"Module Option Scroll Bar", true},

	   MAKE_COMBOBOX("Module Option Open Button", "Dots",
		   {"Off", "Dots", "Arrow", "Future"}),

	   {"Module Option Wheel Sensitivity", 36.0f},
	   {"Module Option Arrow Key Speed", 5.0f},
	   {"Module Option Key Color", "245;245;245;255"},
	   {"Module Option Boolean Box Color", "52;165;248;255"},
	   
	   {"Module Option Help Font Size", 35},
	   {"Module Option Editing Mask Alpha (0~1)", 0.6f},
	   
	   MAKE_COMBOBOX("Module Option Background Color", "Black",
		   {"Flow", "Transparent", NAMED_COLOR_BASE_LIST}),

	   {"Module Option Background Darkness (0~1)", 0.8f},
	   {"Module Option Background Opacity Min (0~1)", 0.85f},
	   {"Module Option Background Opacity Max (0~1)", 0.95f},

	   {"Reset Button Confirmation", true},

	   {"NL Window Shadow", true},
	   {"NL Window Shadow Thickness", 20.0f},
	   {"NL Window Shadow Opacity (0~1)", 0.7f},

	   MAKE_COMBOBOX("NL Window Shadow Color", "Black",
		   {NAMED_COLOR_BASE_LIST}),

	   {"NL Panel Background Opacity (0~1)", 0.95f},
	   {"NL Roundness Global Scale", 0.4f},
	   {"NL Module Option Max Items", 15L},
	   {"NL Page Transition Duration (ms)", 150L},
	   {"NL Card Hover Fade Duration (ms)", 300L},

	   MAKE_COMBOBOX("NL Page Transition", "Right",
		   {"Off", "Fade", "Left", "Right"}),

	   {"NL Title Texture", "neverlose.png"},

	   MAKE_COMBOBOX("NL User Icon", "Auto",
		   {"Auto", "user.png", "steve.png", "creeper.png", "wormwaker.png", "penguin.png", "notch.png", "zi__min.png"},
		   ),

	   {"NL User Icon Circle", true},

	   {"Top Tab Font Size", 20},
	   {"Top Tab Text Color", "253;249;0;255"},
	   {"Module Font Size", 23},
	   {"Module Text Color", "200;200;200;255"},
	   {"Module Text Color (Enabled)", "200;200;200;255"},
	   {"Module Text Color (Unavailable)", "150;150;150;255"},
	   {"Tab Theme Color", "10;10;10"},
	   {"Module Hover Background Color", "65;55;45;230"},
	   {"Module Height", 37},

	   {"ClickGUI Global Scale", 100.0},
	   {"ClickGUI Arrow Key Move Speed", 20.0f},
	   {"ClickGUI Wheel Move Speed", 64.0f},
	   {"ClickGUI Ctrl+Wheel Zoom", true},

	   MAKE_COMBOBOX("ClickGUI Wheel Action", "Vertical Move",
		   {"Off", "Vertical Move", "Old"}),

	   {"Hacked Module Names", false},
	   {"Remove Spaces in Module Names", false},
	   {"Custom Image Path", ""},
	   {"Custom Image Opacity (0~1)", 1.0f},
	   {"Custom Image Scale", 100.0f},
	   {"Custom Image Moving Speed", 0.0f},
	   {"Custom Image Clip", false},
	   {"Custom Image Clip X Start Rate", 0.0f},
	   {"Custom Image Clip X End Rate", 1.0f},
	   {"Custom Image Clip Y Start Rate", 0.25f},
	   {"Custom Image Clip Y End Rate", 0.75f},
	   {"Bottom-Left Tip", true},
	   {"Bottom-Left Tip Font Size", 24},

	   {"Msgbox2 Text Font Size", 30},

	   MAKE_COMBOBOX("Chat Box Animation", "Off",
		   {"Off", "Fade", "Slide (Top)", "Slide (Bottom)", "Slide (Left)", "Slide (Right)",
			"Enlarge", "Enlarge II", "Shrink", "Shrink II"
		   }),

	   {"Chat Box Animation Duration (ms)", 500L},
	   {"Chat Box Y Rate", 1.0f},
	   {"Chat Box Font Size", 50},
	   {"Chat Box Opacity (0~1)", 0.6f},
	   {"Chat Box Font Name", "Calibri"},
	   {"Chat Box Animation FPS", 30.0f},
	   {"Chat Box Max Count", 5},

	   {"ImGui Input Box Width", 750.0f},
	   {"ImGui Move With Arrow Keys", false},
	   {"ImGui Resize With Ctrl+Arrow Keys", false},

	   MAKE_COMBOBOX("Custom Image", "Off",
		   {"Off", "Clip", "Center", "Bottom-Left", "Bottom-Right", "Bottom-Center"}),

	   MAKE_COMBOBOX("Tab Name Case Style", "Normal",
	   {"Normal", "Upper Case", "Lower Case", "Annoying Case"/*, "Fancy Letters"*/}),

	   MAKE_COMBOBOX("Module Name Case Style", "Normal",
	   {"Normal", "Upper Case", "Lower Case", "Annoying Case"/*, "Fancy Letters"*/}),

	   MAKE_COMBOBOX("Tab Name Alignment", "Left",
	   {"Center", "Left", "Right"}),

	   MAKE_COMBOBOX("Module Name Alignment", "Left",
	   {"Center", "Left", "Right"}),

	   {"Module Keybind Display", true},

	   MAKE_COMBOBOX("Module Keybind Color", "Gray",
		   { "Same", "Flow", NAMED_COLOR_BASE_LIST}),

		   MAKE_COMBOBOX("Module Background Color (Enabled)", "Rainbow",
		   {"Transparent", "Flow", NAMED_COLOR_BASE_LIST}),

	   MAKE_COMBOBOX("Module Background Color", "Black",
	   {"Transparent", NAMED_COLOR_BASE_LIST}),

	   {"Module Background Blackness (0~1)", 0.0f},
	   {"Module Background Opacity (0~1)", 1.0f},
	   {"Module Left Bar", false},

	   MAKE_COMBOBOX("Tab Width Mode", "Fixed",
		   {"Auto", "Fixed"}),

		{"Tab Width Minimum (Auto)", 170},
		{"Tab Width Maximum (Auto)", 600},
		{"Tab Width Addition (Auto)", 0},
		{"Tab Width (Fixed)", 290},
		{"Tab Animation Delay Enabled", true},
		{"Tab Animation Delay", 28L},
		{"Tab Animation Expansion", true},
	    {"Tab Shadows", true},
		{"Tab Shadows Thickness", 30.0f},
		{"Tab Shadows Opacity (0~1)", 0.7f},
	    {"Tab Limit Coords", false},
	    {"Tab Expand Arrow", true},
	    {"Tab Expand Animation Duration (ms)", 300L},
	    {"Tab Icons", true},
	    {"Dropdown Auto Avoid Column Overlap", true},

		MAKE_COMBOBOX("Tab Icon Color", "White",
			{NAMED_COLOR_BASE_LIST}),

		MAKE_COMBOBOX("Description Position", "Bottom",
			{"Bottom", "Follow"}),

		MAKE_COMBOBOX("Description Color", "Red-Orange",
			{NAMED_COLOR_BASE_LIST}),

		/*MAKE_COMBOBOX("Tab Shadows Color", "Black",
			{NAMED_COLOR_BASE_LIST}),*/

		{"Description Opacity (0~1)", 1.0},
		   
	   {"Description Font Size", 25},
	   // {"Modules Column Top", 40},
   //	{"Support RCtrl Toggle", true},

	   /*MAKE_COMBOBOX("Menu Toggle Key", "RCtrl/RShift",
		   {"RCtrl", "RShift", "RCtrl/RShift"}),*/

	   {"Menu Toggle Key 1", {{"Keybind", {VK_RMENU}}}},
	   {"Menu Toggle Key 2", {{"Keybind", {VK_LCONTROL, VK_LMENU, VK_INSERT}}}},

	   MAKE_COMBOBOX("Menu Toggle Animation", "Slide (Top)",
		   {"Off", "Fade", "Slide (Top)", "Slide (Bottom)", "Slide (Left)", "Slide (Right)",
			"Enlarge", "Enlarge II", "Shrink", "Shrink II"
		   }),

	   {"Menu Toggle Animation Duration (ms)", 400L},

	   MAKE_COMBOBOX("Requirement Icon", "On",
		   {"Off", "On"}),

	   {"Always Focused", false},
	   //{"Show FPS", true},
	   {"Show Module Description", true},
	   {"Save Integration Options Status Data", true},
	   {"Save Tabs Status Data", true},

	   MAKE_COMBOBOX("Launcher UI Style", "Matrix",
	   {"Default", "Vape", "Jackal", "Neon", "Matrix", "Aurora", "Random"}),

	   {"Launcher Shaking", false},

		/*{"Font Name", "Minecraft Unpixelated.ttf"},*/
		MAKE_COMBOBOX("Font", "GoogleSans.ttf",
		{
			"Minecraft AE Pixel.ttf",
		//"crafters-delight.ttf",
		//"fs-roundcraft.ttf",
			//"msyh.ttc",
			//"DingTalk JinBuTi.ttf",
			"GoogleSans.ttf",
			"HarmonyOS_SansSC_Medium.ttf",
			"Custom"
			//"Metropolis-Medium.ttf",
			/*"Nirmala.ttf",*/
			//"ubuntu.ttf",
		/*	"STXIHEI.ttf",*/
			//"segmono_boot.ttf",
	/*		"segoeui.ttf",*/
	/*		"Tahoma.ttf",*/
			//"Unifont.ttf",
			}),

	   {"Custom Font Path", "C:\\Windows\\Fonts\\seguisb.ttf"},

		MAKE_COMBOBOX("Font Reload Policy (for Non-ASCII)", "Update Record, Dynamic",
			{"Deny", "Fixed Record, Dynamic", "Update Record, Dynamic", "Dynamic",
					"Fixed Record, Deny", "Update Record, Deny"}),

		MAKE_COMBOBOX("Font Non-ASCII Character Record", "Basic",
			{"Basic", "Extended"}),

		{"Font Reload Cooldown (ms)", 400U},

		MAKE_COMBOBOX("Font Texture Filter", "Trilinear",
			{"Point", "Bilinear", "Trilinear"}),

		{"Font Import Size", 50},

		MAKE_COMBOBOX("Language/语言", "English",
			{"English", "简体中文", "繁體中文", "繁體中文（香港）", "繁體中文（臺灣）", "繁體中文（日本）"}),

	    {"Chinese Translation Buffer", true},
	    {"Chinese Translation Cooldown (ms)", 200L},
	    {"Chinese Translation Cache Files", true},

		MAKE_COMBOBOX("Esc Key Action", "Close Menu",
		{"None", "Close Menu", "Exit"}),

		{"Scroll Text Speed", 1.0f},

	   {"Search Wheel Sensitivity", 75.0f },
	   {"Search Module Options", false},
	   {"Profile List Width", 600},
	   {"Profile List Height Rate", 0.55f},
	   {"Profile Show Invalid", false},
	   MAKE_COMBOBOX("Profile Page Style", "Tile",
		   {"List", "Tile"}),
	   {"NL Close Menu When Click Outside", true},
	}
},

{"HUD",

	{
		{"HUD Enabled", true},

			MAKE_COMBOBOX("FPS Display", "Menu On",
				{"Off", "Menu Off", "Menu On", "Always"}),

			{"FPS Font Size", 60},
			{"FPS Opacity (0~1)", 0.6f},
			{"FPS X Rate", 0.3},
			{"FPS Y Rate", 0.01},

			MAKE_COMBOBOX("Client Watermark Display", "Menu On",
				{"Off", "Menu Off", "Menu On", "Always"}),

			MAKE_COMBOBOX("Client Watermark Style", "Jackal",
				{"Jackal", "Jackal Ver", "JackalClient", "JackalClient Ver"}),

			MAKE_COMBOBOX("Client Watermark Case Style", "Normal",
				{"Normal", "Upper Case", "Lower Case", "Annoying Case"/*, "Fancy Letters"*/}),

			MAKE_COMBOBOX("Client Watermark Main Color", "Rainbow",
				{NAMED_COLOR_BASE_LIST}),

			{"Client Watermark Font Size", 60},
			{"Client Watermark Opacity Min (0~1)", 0.2f},
			{"Client Watermark Opacity Max (0~1)", 0.8f},
			{"Client Watermark X Rate", 0.01},
			{"Client Watermark Y Rate", 0.01},
			
			MAKE_COMBOBOX("FPS Color", "Green",
			{NAMED_COLOR_BASE_LIST}),

			{"Chatter Line Gap", 10},
			{"Chatter Show Duration", 10000U},
			{"Chatter Font Size", 60},
			{"Chatter Opacity (0~1)", 0.8f},

			MAKE_COMBOBOX("Chatter Movement", "Linear",
			 {"Linear", "EaseInOutSine"}),

			MAKE_COMBOBOX("Chatter Row Decision", "Auto",
			    {"Auto", "Random"}),

			MAKE_COMBOBOX("Chatter Outline", "Shadow",
				{"Off", "Shadow", "Stroke"}),

			{"Enable Some Tray Tips", true},

			//{"Show Font Extra Chars", false},
			{"Rainbow Speed", 60.0f},
			/*{"Welcome Splash", false}*/
			//{"Superb Notify", false},
			/*MAKE_COMBOBOX("Startup Interface", "Classic",
				{"Off", "Zoom", "Classic", "Fade"}),*/
	}
},

{"Sound",
	{
		{"Notification Sound", true},
		{"Tray Tip Sound", true},
		{"Sound When Hidden", false},
		{"Option Sound Enabled", true},
#ifdef PROFESSIONAL_VERSION
		{"Startup Sound (PRO)", true},
#else
		{"Startup Sound (PRO)", false},
#endif
		{"Top Tab Sound", true},
		{"Profiles Page Sound", true},
		{"About Page Sound", true},
		//{"Reinitialize When Audio Device Changed", true},

		MAKE_SOUNDITEM("Sound (Info)", "steam_show_modal.wav"),
		MAKE_SOUNDITEM("Sound (Warn)", "steam_warning.wav"),
		MAKE_SOUNDITEM("Sound (Error)", "steam_confirm_negative.wav"),
		MAKE_SOUNDITEM("Sound (Success)", "steam_confirm_positive.wav"),
		MAKE_SOUNDITEM("Sound (Enable)", "enable.wav"),
		MAKE_SOUNDITEM("Sound (Disable)", "disable.wav"),
	}
},
};


json gui_style_presets
{
	/*{"Default", 
	},*/
{"Old",
{
	{"Round Corners", true},
	{"Outline", true},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Left"},
	{"Module Background Color (Enabled)", "Rainbow"},
	{"Module Background Color", "Black"},
	{"Module Background Blackness (0~1)", 0.8f},
	{"Module Background Opacity (0~1)", 0.9f},
	{"Module Option Style", "Old"},
	{"Font", "GoogleSans.ttf"},
	{"Menu Toggle Animation", "Slide (Top)"},
	{"Show Module Description", true},
	{"Remove Spaces in Module Names", false},
	{"Module Font Size", 28},
	{"Module Height", 33},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "200;200;200"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color", "40;40;50"},
	{"Tab Theme Color Mode", "Single"},
	{"Tab Name Alignment", "Left"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Auto"},
	{"Tab Width Addition (Auto)", 50},
	{"Top Tab Text Color", "230;230;230"},
	{"Tab Expand Arrow", false},
	{"Tab Icons", false},
	{"Tab Shadows", true},
	{"Tab Shadows Thickness", 10.0f},
	{"Tab Shadows Opacity (0~1)", 0.7f},
	{"Module Left Bar", false},
	{"Module Keybind Display", false},
	{"Module Option Open Button", "Off"},
}
},

{"Modern",
{
	{"Round Corners", true},
	{"Outline", true},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Left"},
	{"Module Background Color (Enabled)", "White"},
	{"Module Background Color", "Transparent"},
	{"Module Background Blackness (0~1)", 0.0f},
	{"Module Background Opacity (0~1)", 1.0f},
	{"Module Option Style", "Integration"},
	{"Font", "GoogleSans.ttf"},
	{"Menu Toggle Animation", "Slide (Bottom)"},
	{"Show Module Description", false},
	{"Remove Spaces in Module Names", false},
	{"Module Font Size", 23},
	{"Module Height", 37},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "200;200;200"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Module Option Background Color", "Transparent"},
	{"Module Option Background Darkness (0~1)", 0.0f},
	{"Tab Theme Color", "10;10;10;10"},
	{"Tab Theme Color Mode", "Single"},
	{"Tab Name Alignment", "Left"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Fixed"},
	{"Tab Width (Fixed)", 290},
	{"Top Tab Text Color", "230;230;230"},
	{"Tab Expand Arrow", true},
	{"Tab Icons", true},
	{"Tab Icon Color", "White"},
	{"Tab Shadows", true},
	{"Tab Shadows Thickness", 20.0f},
	{"Tab Shadows Opacity (0~1)", 0.7f},
	{"Module Left Bar", false},
	{"Module Keybind Display", true},
	{"Module Keybind Color", "Gray"},
	{"Module Option Open Button", "Arrow"},
}
},

{"Vape",
{
	{"Round Corners", false},
	{"Outline", false},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Left"},
	{"Module Background Color (Enabled)", "Rainbow"},
	{"Module Background Color", "Black"},
	{"Module Background Blackness (0~1)", 0.0f},
	{"Module Background Opacity (0~1)", 1.0f},
	{"Module Option Style", "Integration"},
	{"Font", "GoogleSans.ttf"},
	{"Menu Toggle Animation", "Fade"},
	{"Show Module Description", false},
	{"Remove Spaces in Module Names", true},
	{"Module Font Size", 23},
	{"Module Height", 37},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "200;200;200"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color", "10;10;10"},
	{"Tab Theme Color Mode", "Single"},
	{"Tab Name Alignment", "Left"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Fixed"},
	{"Tab Width (Fixed)", 290},
	{"Top Tab Text Color", "230;230;230"},
	{"Tab Expand Arrow", true},
	{"Tab Icons", true},
	{"Tab Icon Color", "White"},
	{"Tab Shadows", true},
	{"Tab Shadows Thickness", 20.0f},
	{"Tab Shadows Opacity (0~1)", 0.7f},
	{"Module Left Bar", false},
	{"Module Keybind Display", true},
	{"Module Keybind Color", "Gray"},
	{"Module Option Open Button", "Dots"},
}
},

{"Opai",
{
	{"Round Corners", true},
	{"Outline", false},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Left"},
	{"Module Background Color (Enabled)", "Gold"},
	{"Module Background Color", "Black"},
	{"Module Background Blackness (0~1)", 0.0f},
	{"Module Background Opacity (0~1)", 1.0f},
	{"Module Option Style", "Integration"},
	{"Font", "GoogleSans.ttf"},
	{"Menu Toggle Animation", "Enlarge II"},
	{"Show Module Description", false},
	{"Remove Spaces in Module Names", false},
	{"Module Font Size", 23},
	{"Module Height", 50},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "20;20;20"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color", "10;10;10"},
	{"Tab Theme Color Mode", "Single"},
	{"Tab Name Alignment", "Left"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Fixed"},
	{"Tab Width (Fixed)", 320},
	{"Top Tab Text Color", "230;230;230"},
	{"Tab Expand Arrow", false},
	{"Tab Icons", false},
	{"Tab Shadows", true},
	{"Tab Shadows Thickness", 30.0f},
	{"Tab Shadows Opacity (0~1)", 0.8f},
	{"Module Left Bar", false},
	{"Module Keybind Display", false},
	{"Module Option Open Button", "Off"},
}
},


{"LiquidBounce",
{
	{"Round Corners", false},
	{"Outline", false},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Left"},
	{"Module Background Color (Enabled)", "Aqua"},
	{"Module Background Color", "Black"},
	{"Module Background Blackness (0~1)", 0.0f},
	{"Module Background Opacity (0~1)", 0.7f},
	{"Module Option Style", "Integration"},
	{"Menu Toggle Animation", "Fade"},
	{"Font", "GoogleSans.ttf"},
	{"Show Module Description", true},
	{"Remove Spaces in Module Names", true},
	{"Module Font Size", 27},
	{"Module Height", 32},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "200;200;200"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color Mode", "Single"},
	{"Tab Theme Color", "58;71;94"},
	{"Tab Name Alignment", "Center"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Fixed"},
	{"Tab Width (Fixed)", 270},
	{"Top Tab Text Color", "200;200;200"},
	{"Tab Expand Arrow", false},
	{"Tab Icons", true},
	{"Tab Icon Color", "Blue"},
	{"Tab Shadows", false},
	{"Module Left Bar", false},
	{"Module Keybind Display", false},
	{"Module Option Open Button", "Off"},
}
},

{"LiquidBounce NextGen",
{
	{"Round Corners", false},
	{"Outline", false},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Center"},
	{"Module Background Color (Enabled)", "Black"},
	{"Module Background Color", "Black"},
	{"Module Background Blackness (0~1)", 0.0f},
	{"Module Background Opacity (0~1)", 1.0f},
	{"Module Option Style", "Integration"},
	{"Menu Toggle Animation", "Fade"},
	{"Font", "GoogleSans.ttf"},
	{"Show Module Description", true},
	{"Requirement Icon", "Off"},
	{"Remove Spaces in Module Names", false},
	{"Module Font Size", 21},
	{"Module Height", 39},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "89;118;247"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color Mode", "Single"},
	{"Tab Theme Color", "32;34;37;190"},
	{"Tab Name Alignment", "Left"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Fixed"},
	{"Tab Width (Fixed)", 280},
	{"Top Tab Text Color", "aqua"},
	{"Tab Expand Arrow", true},
	{"Tab Icons", true},
	{"Tab Shadows", true},
	{"Tab Shadows Thickness", 20.0f},
	{"Tab Shadows Opacity (0~1)", 0.6f},
	{"Module Left Bar", false},
	{"Module Keybind Display", false},
	{"Module Option Open Button", "Arrow"},
}
},


{"Raven",
{
	{"Round Corners", true},
	{"Outline", true},
	{"Font", "Minecraft AE Pixel.ttf"},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Center"},
	{"Module Background Color (Enabled)", "Black"},
	{"Module Background Color", "Black"},
	{"Module Background Blackness (0~1)", 0.0f},
	{"Module Background Opacity (0~1)", 0.6f},
	{"Module Option Style", "Integration"},
	{"Menu Toggle Animation", "Fade"},
	{"Show Module Description", true},
	{"Remove Spaces in Module Names", true},
	{"Module Font Size", 15},
	{"Module Height", 40},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "89;118;247"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color Mode", "Single"},
	{"Tab Theme Color", "32;34;37;210"},
	{"Tab Name Alignment", "Left"},
	{"Tab Name Case Style", "Lower Case"},
	{"Tab Width Mode", "Fixed"},
	{"Tab Width (Fixed)", 270},
	{"Top Tab Text Color", "180;180;180"},
	{"Tab Expand Arrow", true},
	{"Tab Icons", false},
	{"Tab Shadows", false},
	{"Module Left Bar", false},
	{"Module Keybind Display", false},
	{"Module Option Open Button", "Off"},
}
},

{"Meteor",
{
	{"Round Corners", false},
	{"Outline", false},
	{"Font", "GoogleSans.ttf"},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Center"},
	{"Module Background Color (Enabled)", "Gray"},
	{"Module Background Color", "Black"},
	{"Module Background Blackness (0~1)", 0.0f},
	{"Module Background Opacity (0~1)", 1.0f},
	{"Module Option Style", "Old"},
	{"Menu Toggle Animation", "Fade"},
	{"Show Module Description", true},
	{"Remove Spaces in Module Names", false},
	{"Module Font Size", 25},
	{"Module Height", 30},
	{"Module Text Color", "200;200;200"},
	{"Module Text Color (Enabled)", "200;200;200"},
	{"Module Text Color (Unavailable)", "150;150;150"},
	{"Tab Theme Color Mode", "Single"},
	{"Tab Theme Color", "124;30;235"},
	{"Tab Name Alignment", "Center"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Fixed"},
	{"Tab Width (Fixed)", 280},
	{"Top Tab Text Color", "180;180;180"},
	{"Tab Expand Arrow", true},
	{"Tab Icons", false},
	{"Tab Shadows", false},
	{"Module Left Bar", true},
	{"Module Keybind Display", false},
	{"Module Option Open Button", "Off"},
}
},

{ "Future",
{
	{"Round Corners", false},
	{"Outline", false},
	{"Font", "GoogleSans.ttf"},
	{"Module Name Case Style", "Normal"},
	{"Module Name Alignment", "Left"},
	{"Module Background Color (Enabled)", "Red"},
	{"Module Background Color", "Red"},
	{"Module Background Blackness (0~1)", 0.9f},
	{"Module Background Opacity (0~1)", 0.6f},
	{"Module Option Style", "Integration"},
	{"Menu Toggle Animation", "Slide (Top)"},
	{"Show Module Description", true},
	{"Remove Spaces in Module Names", false},
	{"Module Font Size", 25},
	{"Module Height", 30},
	{"Module Text Color", "153;153;153"},
	{"Module Text Color (Enabled)", "250;250;250"},
	{"Module Text Color (Unavailable)", "90;90;90"},
	{"Tab Theme Color Mode", "Single"},
	{"Tab Theme Color", "129;31;23"},
	{"Tab Name Alignment", "Left"},
	{"Tab Name Case Style", "Normal"},
	{"Tab Width Mode", "Fixed"},
	{"Tab Width (Fixed)", 280},
	{"Top Tab Text Color", "180;180;180"},
	{"Tab Expand Arrow", false},
	{"Tab Icons", false},
	{"Tab Shadows", false},
	{"Module Left Bar", true},
	{"Module Keybind Display", false},
	{"Module Option Open Button", "Future"},
}
},
};

