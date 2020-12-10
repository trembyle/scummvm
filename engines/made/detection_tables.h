/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef MADE_DETECTION_TABLES_H
#define MADE_DETECTION_TABLES_H

#include "engines/advancedDetector.h"
#include "common/translation.h"

namespace Made {

static const MadeGameDescription gameDescriptions[] = {
	
	// Dates can be obtained from the top of the READ.ME file

	{
		// Return to Zork - English CD version 1.0 09/15/93
		// Patch #1953654 submitted by spookypeanut
		{
			"rtz",
			"V1.0 09/15/93, CD",
			{
				{ "rtzcd.red", 0, "cd8b62ece4677c438688c1de3f5379b9", 285233 },
				{ "rtzcd.prj", 0, "974d74410c3c29d50e857863e8bf40e2", 43016792 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_CD,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD_COMPRESSED,
		3,
	},

	{
		// Return to Zork - English OEM CD version 1.1 12/07/93
		// Labeled "Not for separate resale. This product is only to
		// be sold with computer hardware or peripheral devices."
		// This version is currently distributed through GOG.com.
		{
			"rtz",
			"V1.1 12/07/93, OEM CD",
			{
				{ "rtzcd.red", 0, "c4e2430e6b6c6ff1562a80fb4a9df24c", 276177 },
				{ "rtzcd.prj", 0, "974d74410c3c29d50e857863e8bf40e2", 43016792 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_CD,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD_COMPRESSED,
		3,
	},

	{
		// Return to Zork - English Retail CD version 1.1 12/07/93
		{
			"rtz",
			"V1.1 12/07/93, Retail CD",
			{
				{ "rtzcd.red", 0, "c4e2430e6b6c6ff1562a80fb4a9df24c", 276466 },
				{ "rtzcd.prj", 0, "974d74410c3c29d50e857863e8bf40e2", 43016792 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_CD,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD_COMPRESSED,
		3,
	},

	// TODO - determine if 1.1 or 1.2 patches have been applied to earlier versions
	{
		// Return to Zork - English CD version 1.2 09/29/94
		{
			"rtz",
			"V1.2 09/29/94, CD",
			{
				{ "rtzcd.red", 0, "946997d8b0aa6cb4e848bad02a1fc3d2", 276584 },
				{ "rtzcd.prj", 0, "974d74410c3c29d50e857863e8bf40e2", 43016792 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_CD,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD_COMPRESSED,
		3,
	},

	{
		// Return to Zork - German CD version 1.2 09/29/94
		// Supplied by Dark-Star in the ScummVM forums
	
		// Translation patch by BumbleBee can be applied to GOG.com release:
		// https://www.compiware-forum.de/forum/thread/45413-return-to-zork-german-patch/
		{
			"rtz",
			"V1.2 09/29/94, CD",
			{
				{ "rtzcd.red", 0, "946997d8b0aa6cb4e848bad02a1fc3d2", 355442 },
				{ "rtzcd.prj", 0, "9bb3d2cd9fabd959f976af5d6c2c8412", 48464530 },
				AD_LISTEND
			},
			Common::DE_DEU,
			Common::kPlatformDOS,
			ADGF_CD,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD_COMPRESSED,
		3,
	},

	{
		// Return to Zork - Italian CD version 1.2 03/31/95
		// Patch #2685032 submitted by goodoldgeorg
		{
			"rtz",
			"V1.2 03/31/95, CD",
			{
				{ "rtzcd.red", 0, "946997d8b0aa6cb4e848bad02a1fc3d2", 354971 },
				{ "rtzcd.prj", 0, "fd78e601c86e2ca1a60b858acb0a7760", 65658222 },
				AD_LISTEND
			},
			Common::IT_ITA,
			Common::kPlatformDOS,
			ADGF_CD,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD_COMPRESSED,
		3,
	},

	{
		// Return to Zork - French CD version 1.2 05/13/95
		// Patch #2685032 submitted by goodoldgeorg
		{
			"rtz",
			"V1.2 05/13/95, CD",
			{
				{ "rtzcd.red", 0, "946997d8b0aa6cb4e848bad02a1fc3d2", 354614 },
				{ "rtzcd.prj", 0, "f2412cb3e70182c8bea9225b0e0efa00", 64574088 },
				AD_LISTEND
			},
			Common::FR_FRA,
			Common::kPlatformDOS,
			ADGF_CD,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD_COMPRESSED,
		3,
	},

	{
		// Return to Zork - Korean CD version 1.2 09/29/94
		// Dub only. No text was translated, even in menus.
		// There are no new fonts to deal with (unlike Japanese).
		// submitted by trembyle
		{
			"rtz",
			"V1.2 09/29/94, CD",
			{
				{ "rtzcd.red", 0, "946997d8b0aa6cb4e848bad02a1fc3d2", 276584 },
				{ "rtzcd.prj", 0, "3c8644f7ce77b74968637c035c3532d8", 48083511 },
				AD_LISTEND
			},
			Common::KO_KOR,
			Common::kPlatformDOS,
			ADGF_CD,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD_COMPRESSED,
		3,
	},

	{
		// Return to Zork - Chinese CD version 1.2 10/20/94
		// Dub only. No text was translated, even in menus, so there are
		// no font issues. Also, with no text, we don't need to distinguish
		// Traditional or Simplified script, hence ZH_ANY.
		// submitted by trembyle
		{
			"rtz",
			"V1.2 09/15/93, CD",
			{
				{ "rtzcd.red", 0, "cd8b62ece4677c438688c1de3f5379b9", 283663 },
				{ "rtzcd.prj", 0, "df5669fb117bbaf8d3b289d4b1e8f14e", 72228821 },
				AD_LISTEND
			},
			Common::ZH_ANY,
			Common::kPlatformDOS,
			ADGF_CD,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD_COMPRESSED,
		3,
	},

	{
		// Return to Zork - ReelMagic MPEG version 05/25/94
		// Required Sigma Designs ReelMagic hardware MPEG decoder card
		// MPEG versions are not currently supported
		{
			"rtz",
			"MPEG video is not yet supported",
			{
				{ "rtzrm.red", 0, "861470fa722260217127c7e5c1b1ff4a", 278708 },
				{ "rtzrm.prj", 0, "764d02f52ce1c219f2c0066677fba4ce", 21117714 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_CD | ADGF_UNSUPPORTED,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_MPEG,
		3,
	},

	// Mac versions are currently unsupported
	// These will need to enforce hires graphics
	{
		// Return to Zork - Mac version unknown (no VERS resource)
		// File date on RTZ.DAT is 05/21/94
		{
			"rtz",
			"Mac versions are not yet supported",
			{
				{ "rtz.dat", 0, "8a9a65e0588f8a6f753d1dfff8179e08", 606336 },
				{ "rtz.prj", 0, "a3fd7fc9479686008a8bae8109682569", 47547412 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformMacintosh,
			ADGF_CD | ADGF_UNSUPPORTED,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_MAC,
		3,
	},

	{
		// Return to Zork - Mac version 1.1.1 02/09/95
		// Compilation with Zork Anthology and Blackthorne
		{
			"rtz",
			"Mac versions are not yet supported",
			{
				{ "rtz.dat", 0, "9899632d9276f2e4090775ea99070315", 609518 },
				{ "rtz.prj", 0, "315933997abc0400e388c1bc02277e19", 47547412 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformMacintosh,
			ADGF_CD | ADGF_UNSUPPORTED,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_MAC,
		3,
	},

	{
		// Return to Zork - Mac MPEG version 1.1.1 07/12/95
		// Required Apple MPEG Media System hardware decoder
		// MPEG versions are not currently supported
		{
			"rtz",
			"Mac versions are not yet supported",
			{
				{ "rtz.dat", 0, "289f896ae8c3b5829104991b44825ebb", 602112 },
				{ "rtz.prj", 0, "b9d0f34207dc2b2f35b34c8c35b16fbf", 47547284 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformMacintosh,
			ADGF_CD | ADGF_UNSUPPORTED,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_MAC,
		3,
	},

	// Japanese versions are currently unsupported. All three platforms
	// were released on the FM Towns CD. We differentiate by using the
	// RTZCD.DAT file in the each platform's directory.

	// These versions were localized by Data West as product code
	// DWHB4028. There were also standalone releases for DOS/V and
	// PC-98 DOS. All of these share the same product code. Possibly
	// there was an MPEG version released for the PC-9821Cb (CanBe)
	// models, which came pre-installed with MPEG boards.

	// All Japanese entries below are version 1.2 10/08/94.
	{
		// Return to Zork - Japanese DOS
		// This is the RTZCD.DAT in the base directory of the FM Towns CD
		{
			"rtz",
			"Japanese fonts are not yet supported",
			{
				{ "rtzcd.dat", 0, "c4fccf67ad247f09b94c3c808b138576", 537088 },
				{ "rtzcd.prj", 0, "8c1be62f0d4fbf423d709be8b9eb4730", 45396765 },
				AD_LISTEND
			},
			Common::JA_JPN,
			Common::kPlatformDOS,
			ADGF_CD | ADGF_UNSUPPORTED,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD,
		3,
	},

	{
		// Return to Zork - Japanese FM Towns
		// This is in the RTZFM directory of the FM Towns CD
		{
			"rtz",
			"Japanese fonts are not yet supported",
			{
				{ "rtzcd.dat", 0, "e949a6a42d82daabfa7d4dc0a87a9843", 537088 },
				{ "rtzcd.prj", 0, "8c1be62f0d4fbf423d709be8b9eb4730", 45396765 },
				AD_LISTEND
			},
			Common::JA_JPN,
			Common::kPlatformFMTowns,
			ADGF_CD | ADGF_UNSUPPORTED,
			GUIO1(GUIO_NOASPECT)
		},
		GID_RTZ,
		0,
		GF_CD,
		3,
	},

	{
		// Return to Zork - Japanese PC-98
		// This is in the RTZ9821 directory of the FM Towns CD
		{
			"rtz",
			"Japanese fonts are not yet supported",
			{
				{ "rtzcd.dat", 0, "0c0117e98530c736a141c2aad6834dc5", 537088 },
				{ "rtzcd.prj", 0, "8c1be62f0d4fbf423d709be8b9eb4730", 45396765 },
				AD_LISTEND
			},
			Common::JA_JPN,
			Common::kPlatformPC98,
			ADGF_CD | ADGF_UNSUPPORTED,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD,
		3,
	},

	{
		// Return to Zork - English floppy version 09/09/93
		// Run installer to make full RTZ.PRJ file from disks
		{
			"rtz",
			"Floppy",
			{
				{ "rtz.dat", 0, "3df3bcc293724405c37debd5e59c2ce4", 508928 },
				{ "rtz.prj", 0, "764d02f52ce1c219f2c0066677fba4ce", 21117714 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_NO_FLAGS,
			GUIO1(GUIO_NOSPEECH)
		},
		GID_RTZ,
		0,
		GF_FLOPPY,
		3,
	},

	{
		// Return to Zork - Shareware "Sneak Preview" Demo 05/21/93
		{
			"rtz",
			"Floppy Demo",
			{
				{ "demo.dat", 0, "2a6a1354bd5346fad4aee08e5b56caaa", 34304 },
				{ "demo.prj", 0, "46891bd6e5180228fe4b3253d500997b", 1675348 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_DEMO,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_DEMO,
		3,
	},

	{
		// Return to Zork - CD Demo version 1.1 12/07/93
		{
			"rtz",
			"CD Demo",
			{
				{ "rtzcd.red", 0, "827cfb323eae37b385985a2359fae3e9", 133784 },
				{ "rtzcd.prj", 0, "974d74410c3c29d50e857863e8bf40e2", 43016792 },
				AD_LISTEND
			},
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_CD | ADGF_DEMO,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_CD_COMPRESSED, // does this use red book audio tracks?
		3,
	},

	// Japanese Console Ports
	// Saturn and PlayStation use MADE engine
	// PC-FX version requires further study
	{
		// Return to Zork - Japanese Sega Saturn T-23401G
		// Published by Bandai Visual / Emotion Digital Software
		// Version 1.000 12/13/95 from disc header
		{
			"rtz",
			"Console ports are not yet supported",
			{
				{ "rtz.dat", 0, "4716b144b8587488e6842b69a879f0cf", 606816 },
				{ "rtz.prj", 0, "0dc912a441b9e5122d7bdd22aaaffc67", 18747792 },
				AD_LISTEND
			},
			Common::JA_JPN,
			Common::kPlatformSaturn,
			ADGF_CD | ADGF_UNSUPPORTED,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_SATURN,
		3,
	},

	{
		// Return to Zork - Japanese Sega Saturn T-23401G Rev.A
		// Published by Bandai Visual / Emotion Digital Software
		// Same disc is used in Zork Collection published by Shoeisha
		// Version 2.000 12/28/95 from disc header
		{
			"rtz",
			"Console ports are not yet supported",
			{
				{ "rtz.dat", 0, "43196a089ee5b7d19594adccb98f590a", 527872 },
				{ "rtz.prj", 0, "e52a9dfbb6e3ba8d8733e2406c7e54b7", 16329696 },
				AD_LISTEND
			},
			Common::JA_JPN,
			Common::kPlatformSaturn,
			ADGF_CD | ADGF_UNSUPPORTED,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_SATURN,
		3,
	},

	{
		// Return to Zork - Japanese PlayStation SLPS-00192
		// Executable date 12/15/95; data file date 06/25/96
		{
			"rtz",
			"Console ports are not yet supported",
			{
				{ "psj_rtz.dat", 0, "e1c738ecc5216b9fd63629861a35efc3", 518144 },
				{ "psj_rtz.prj", 0, "f1d113ec21a4c5ac059e554a95402710", 9018911 },
				AD_LISTEND
			},
			Common::JA_JPN,
			Common::kPlatformPSX,
			ADGF_CD | ADGF_UNSUPPORTED,
			GUIO0()
		},
		GID_RTZ,
		0,
		GF_PSX,
		3,
	},

	// The Manhole: Masterpiece Edition is not a MADE engine and cannot be
	// supported by MADE. It is a HyperCard-like engine.
	{
		// The Manhole: Masterpiece Edition (GOG/CD)
		{
			"manhole",
			_s("The game is using unsupported engine"),
			AD_ENTRY1("manhole.dat", "e8cec9bf21e4c50a7ebc193a4e0b48f5"),
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_UNSUPPORTED,
			GUIO1(GUIO_NOSPEECH)
		},
		GID_MANHOLE,
		0,
		GF_CD,
		2,
	},

	{
		// The Manhole: New and Enhanced
		{
			"manhole",
			"",
			AD_ENTRY1("manhole.dat", "cb21e31ed35c963208343bc995225b73"),
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_CD,
			GUIO1(GUIO_NOSPEECH)
		},
		GID_MANHOLE,
		0,
		GF_CD,
		2,
	},

	{
		// The Manhole (EGA, 5.25")
		{
			"manhole",
			"EGA",
			AD_ENTRY1("manhole.dat", "2b1658292599a861c4cd3cf6cdb3c581"),
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_NO_FLAGS,
			GUIO1(GUIO_NOSPEECH)
		},
		GID_MANHOLE,
		0,
		GF_FLOPPY,
		1,
	},

	{
		// Leather Goddesses of Phobos 2 (English)
		{
			"lgop2",
			"",
			AD_ENTRY1("lgop2.dat", "8137996db200ff67e8f172ff106f2e48"),
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_NO_FLAGS,
			GUIO1(GUIO_NOSPEECH)
		},
		GID_LGOP2,
		0,
		GF_FLOPPY,
		2,
	},

	{
		// Leather Goddesses of Phobos 2 (German)
		// Supplied by windlepoons (bug tracker #2675695)
		{
			"lgop2",
			"",
			AD_ENTRY1s("lgop2.dat", "a0ffea6a3b7e39bd861edd00c397641c", 299466),
			Common::DE_DEU,
			Common::kPlatformDOS,
			ADGF_NO_FLAGS,
			GUIO1(GUIO_NOSPEECH)
		},
		GID_LGOP2,
		0,
		GF_FLOPPY,
		2,
	},

	{
		// Leather Goddesses of Phobos 2 (French)
		// Supplied by goodoldgeorg (bug tracker #2675759)
		{
			"lgop2",
			"",
			AD_ENTRY1s("lgop2.dat", "f9e974087af7cf4b7ec2d8dc45d01e0c", 295366),
			Common::FR_FRA,
			Common::kPlatformDOS,
			ADGF_NO_FLAGS,
			GUIO1(GUIO_NOSPEECH)
		},
		GID_LGOP2,
		0,
		GF_FLOPPY,
		2,
	},

	{
		// Leather Goddesses of Phobos 2 (Spanish)
		// Supplied by goodoldgeorg (bug tracker #2675759)
		{
			"lgop2",
			"",
			AD_ENTRY1s("lgop2.dat", "96eb95b4d75b9a3da0b0d67e3b4a787d", 288984),
			Common::ES_ESP,
			Common::kPlatformDOS,
			ADGF_NO_FLAGS,
			GUIO1(GUIO_NOSPEECH)
		},
		GID_LGOP2,
		0,
		GF_FLOPPY,
		2,
	},

	{
		// Rodney's Funscreen
		{
			"rodney",
			"",
			AD_ENTRY1("rodneys.dat", "a79887dbaa47689facd7c6f09258ba5a"),
			Common::EN_ANY,
			Common::kPlatformDOS,
			ADGF_NO_FLAGS,
			GUIO1(GUIO_NOSPEECH)
		},
		GID_RODNEY,
		0,
		GF_FLOPPY,
		2,
	},

	{ AD_TABLE_END_MARKER, 0, 0, 0, 0 }
};

/**
 * The fallback game descriptor used by the Made engine's fallbackDetector.
 * Contents of this struct are to be overwritten by the fallbackDetector.
 */
static MadeGameDescription g_fallbackDesc = {
	{
		"",
		"",
		AD_ENTRY1(0, 0), // This should always be AD_ENTRY1(0, 0) in the fallback descriptor
		Common::UNK_LANG,
		Common::kPlatformDOS,
		ADGF_NO_FLAGS,
		GUIO0()
	},
	0,
	0,
	0,
	0,
};

} // End of namespace Made

#endif
