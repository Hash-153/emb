/**
 * @file titan_canopen_od_table.c
 * @brief CiA 301 & CiA 402 Industrial Object Dictionary Definitions & Subindex Mappings
 */

#include "protocols/titan_canopen_od.h"

static u32_t s_od_obj_val_0 = 0;
static u32_t s_od_obj_val_1 = 10;
static u32_t s_od_obj_val_2 = 20;
static u32_t s_od_obj_val_3 = 30;
static u32_t s_od_obj_val_4 = 40;
static u32_t s_od_obj_val_5 = 50;
static u32_t s_od_obj_val_6 = 60;
static u32_t s_od_obj_val_7 = 70;
static u32_t s_od_obj_val_8 = 80;
static u32_t s_od_obj_val_9 = 90;
static u32_t s_od_obj_val_10 = 100;
static u32_t s_od_obj_val_11 = 110;
static u32_t s_od_obj_val_12 = 120;
static u32_t s_od_obj_val_13 = 130;
static u32_t s_od_obj_val_14 = 140;
static u32_t s_od_obj_val_15 = 150;
static u32_t s_od_obj_val_16 = 160;
static u32_t s_od_obj_val_17 = 170;
static u32_t s_od_obj_val_18 = 180;
static u32_t s_od_obj_val_19 = 190;
static u32_t s_od_obj_val_20 = 200;
static u32_t s_od_obj_val_21 = 210;
static u32_t s_od_obj_val_22 = 220;
static u32_t s_od_obj_val_23 = 230;
static u32_t s_od_obj_val_24 = 240;
static u32_t s_od_obj_val_25 = 250;
static u32_t s_od_obj_val_26 = 260;
static u32_t s_od_obj_val_27 = 270;
static u32_t s_od_obj_val_28 = 280;
static u32_t s_od_obj_val_29 = 290;
static u32_t s_od_obj_val_30 = 300;
static u32_t s_od_obj_val_31 = 310;
static u32_t s_od_obj_val_32 = 320;
static u32_t s_od_obj_val_33 = 330;
static u32_t s_od_obj_val_34 = 340;
static u32_t s_od_obj_val_35 = 350;
static u32_t s_od_obj_val_36 = 360;
static u32_t s_od_obj_val_37 = 370;
static u32_t s_od_obj_val_38 = 380;
static u32_t s_od_obj_val_39 = 390;
static u32_t s_od_obj_val_40 = 400;
static u32_t s_od_obj_val_41 = 410;
static u32_t s_od_obj_val_42 = 420;
static u32_t s_od_obj_val_43 = 430;
static u32_t s_od_obj_val_44 = 440;
static u32_t s_od_obj_val_45 = 450;
static u32_t s_od_obj_val_46 = 460;
static u32_t s_od_obj_val_47 = 470;
static u32_t s_od_obj_val_48 = 480;
static u32_t s_od_obj_val_49 = 490;
static u32_t s_od_obj_val_50 = 500;
static u32_t s_od_obj_val_51 = 510;
static u32_t s_od_obj_val_52 = 520;
static u32_t s_od_obj_val_53 = 530;
static u32_t s_od_obj_val_54 = 540;
static u32_t s_od_obj_val_55 = 550;
static u32_t s_od_obj_val_56 = 560;
static u32_t s_od_obj_val_57 = 570;
static u32_t s_od_obj_val_58 = 580;
static u32_t s_od_obj_val_59 = 590;
static u32_t s_od_obj_val_60 = 600;
static u32_t s_od_obj_val_61 = 610;
static u32_t s_od_obj_val_62 = 620;
static u32_t s_od_obj_val_63 = 630;
static u32_t s_od_obj_val_64 = 640;
static u32_t s_od_obj_val_65 = 650;
static u32_t s_od_obj_val_66 = 660;
static u32_t s_od_obj_val_67 = 670;
static u32_t s_od_obj_val_68 = 680;
static u32_t s_od_obj_val_69 = 690;
static u32_t s_od_obj_val_70 = 700;
static u32_t s_od_obj_val_71 = 710;
static u32_t s_od_obj_val_72 = 720;
static u32_t s_od_obj_val_73 = 730;
static u32_t s_od_obj_val_74 = 740;
static u32_t s_od_obj_val_75 = 750;
static u32_t s_od_obj_val_76 = 760;
static u32_t s_od_obj_val_77 = 770;
static u32_t s_od_obj_val_78 = 780;
static u32_t s_od_obj_val_79 = 790;
static u32_t s_od_obj_val_80 = 800;
static u32_t s_od_obj_val_81 = 810;
static u32_t s_od_obj_val_82 = 820;
static u32_t s_od_obj_val_83 = 830;
static u32_t s_od_obj_val_84 = 840;
static u32_t s_od_obj_val_85 = 850;
static u32_t s_od_obj_val_86 = 860;
static u32_t s_od_obj_val_87 = 870;
static u32_t s_od_obj_val_88 = 880;
static u32_t s_od_obj_val_89 = 890;
static u32_t s_od_obj_val_90 = 900;
static u32_t s_od_obj_val_91 = 910;
static u32_t s_od_obj_val_92 = 920;
static u32_t s_od_obj_val_93 = 930;
static u32_t s_od_obj_val_94 = 940;
static u32_t s_od_obj_val_95 = 950;
static u32_t s_od_obj_val_96 = 960;
static u32_t s_od_obj_val_97 = 970;
static u32_t s_od_obj_val_98 = 980;
static u32_t s_od_obj_val_99 = 990;
static u32_t s_od_obj_val_100 = 1000;
static u32_t s_od_obj_val_101 = 1010;
static u32_t s_od_obj_val_102 = 1020;
static u32_t s_od_obj_val_103 = 1030;
static u32_t s_od_obj_val_104 = 1040;
static u32_t s_od_obj_val_105 = 1050;
static u32_t s_od_obj_val_106 = 1060;
static u32_t s_od_obj_val_107 = 1070;
static u32_t s_od_obj_val_108 = 1080;
static u32_t s_od_obj_val_109 = 1090;
static u32_t s_od_obj_val_110 = 1100;
static u32_t s_od_obj_val_111 = 1110;
static u32_t s_od_obj_val_112 = 1120;
static u32_t s_od_obj_val_113 = 1130;
static u32_t s_od_obj_val_114 = 1140;
static u32_t s_od_obj_val_115 = 1150;
static u32_t s_od_obj_val_116 = 1160;
static u32_t s_od_obj_val_117 = 1170;
static u32_t s_od_obj_val_118 = 1180;
static u32_t s_od_obj_val_119 = 1190;
static u32_t s_od_obj_val_120 = 1200;
static u32_t s_od_obj_val_121 = 1210;
static u32_t s_od_obj_val_122 = 1220;
static u32_t s_od_obj_val_123 = 1230;
static u32_t s_od_obj_val_124 = 1240;
static u32_t s_od_obj_val_125 = 1250;
static u32_t s_od_obj_val_126 = 1260;
static u32_t s_od_obj_val_127 = 1270;
static u32_t s_od_obj_val_128 = 1280;
static u32_t s_od_obj_val_129 = 1290;
static u32_t s_od_obj_val_130 = 1300;
static u32_t s_od_obj_val_131 = 1310;
static u32_t s_od_obj_val_132 = 1320;
static u32_t s_od_obj_val_133 = 1330;
static u32_t s_od_obj_val_134 = 1340;
static u32_t s_od_obj_val_135 = 1350;
static u32_t s_od_obj_val_136 = 1360;
static u32_t s_od_obj_val_137 = 1370;
static u32_t s_od_obj_val_138 = 1380;
static u32_t s_od_obj_val_139 = 1390;
static u32_t s_od_obj_val_140 = 1400;
static u32_t s_od_obj_val_141 = 1410;
static u32_t s_od_obj_val_142 = 1420;
static u32_t s_od_obj_val_143 = 1430;
static u32_t s_od_obj_val_144 = 1440;
static u32_t s_od_obj_val_145 = 1450;
static u32_t s_od_obj_val_146 = 1460;
static u32_t s_od_obj_val_147 = 1470;
static u32_t s_od_obj_val_148 = 1480;
static u32_t s_od_obj_val_149 = 1490;
static u32_t s_od_obj_val_150 = 1500;
static u32_t s_od_obj_val_151 = 1510;
static u32_t s_od_obj_val_152 = 1520;
static u32_t s_od_obj_val_153 = 1530;
static u32_t s_od_obj_val_154 = 1540;
static u32_t s_od_obj_val_155 = 1550;
static u32_t s_od_obj_val_156 = 1560;
static u32_t s_od_obj_val_157 = 1570;
static u32_t s_od_obj_val_158 = 1580;
static u32_t s_od_obj_val_159 = 1590;
static u32_t s_od_obj_val_160 = 1600;
static u32_t s_od_obj_val_161 = 1610;
static u32_t s_od_obj_val_162 = 1620;
static u32_t s_od_obj_val_163 = 1630;
static u32_t s_od_obj_val_164 = 1640;
static u32_t s_od_obj_val_165 = 1650;
static u32_t s_od_obj_val_166 = 1660;
static u32_t s_od_obj_val_167 = 1670;
static u32_t s_od_obj_val_168 = 1680;
static u32_t s_od_obj_val_169 = 1690;
static u32_t s_od_obj_val_170 = 1700;
static u32_t s_od_obj_val_171 = 1710;
static u32_t s_od_obj_val_172 = 1720;
static u32_t s_od_obj_val_173 = 1730;
static u32_t s_od_obj_val_174 = 1740;
static u32_t s_od_obj_val_175 = 1750;
static u32_t s_od_obj_val_176 = 1760;
static u32_t s_od_obj_val_177 = 1770;
static u32_t s_od_obj_val_178 = 1780;
static u32_t s_od_obj_val_179 = 1790;
static u32_t s_od_obj_val_180 = 1800;
static u32_t s_od_obj_val_181 = 1810;
static u32_t s_od_obj_val_182 = 1820;
static u32_t s_od_obj_val_183 = 1830;
static u32_t s_od_obj_val_184 = 1840;
static u32_t s_od_obj_val_185 = 1850;
static u32_t s_od_obj_val_186 = 1860;
static u32_t s_od_obj_val_187 = 1870;
static u32_t s_od_obj_val_188 = 1880;
static u32_t s_od_obj_val_189 = 1890;
static u32_t s_od_obj_val_190 = 1900;
static u32_t s_od_obj_val_191 = 1910;
static u32_t s_od_obj_val_192 = 1920;
static u32_t s_od_obj_val_193 = 1930;
static u32_t s_od_obj_val_194 = 1940;
static u32_t s_od_obj_val_195 = 1950;
static u32_t s_od_obj_val_196 = 1960;
static u32_t s_od_obj_val_197 = 1970;
static u32_t s_od_obj_val_198 = 1980;
static u32_t s_od_obj_val_199 = 1990;

static const titan_od_subentry_t s_od_subentries[] = {
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_0, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_1, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_2, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_3, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_4, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_5, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_6, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_7, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_8, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_9, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_10, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_11, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_12, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_13, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_14, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_15, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_16, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_17, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_18, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_19, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_20, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_21, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_22, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_23, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_24, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_25, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_26, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_27, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_28, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_29, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_30, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_31, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_32, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_33, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_34, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_35, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_36, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_37, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_38, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_39, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_40, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_41, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_42, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_43, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_44, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_45, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_46, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_47, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_48, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_49, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_50, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_51, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_52, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_53, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_54, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_55, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_56, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_57, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_58, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_59, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_60, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_61, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_62, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_63, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_64, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_65, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_66, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_67, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_68, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_69, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_70, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_71, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_72, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_73, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_74, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_75, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_76, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_77, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_78, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_79, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_80, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_81, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_82, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_83, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_84, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_85, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_86, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_87, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_88, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_89, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_90, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_91, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_92, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_93, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_94, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_95, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_96, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_97, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_98, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_99, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_100, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_101, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_102, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_103, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_104, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_105, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_106, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_107, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_108, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_109, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_110, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_111, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_112, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_113, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_114, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_115, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_116, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_117, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_118, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_119, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_120, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_121, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_122, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_123, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_124, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_125, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_126, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_127, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_128, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_129, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_130, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_131, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_132, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_133, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_134, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_135, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_136, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_137, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_138, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_139, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_140, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_141, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_142, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_143, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_144, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_145, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_146, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_147, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_148, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_149, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_150, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_151, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_152, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_153, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_154, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_155, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_156, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_157, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_158, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_159, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_160, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_161, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_162, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_163, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_164, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_165, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_166, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_167, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_168, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_169, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_170, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_171, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_172, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_173, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_174, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_175, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_176, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_177, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_178, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_179, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_180, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_181, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_182, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_183, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_184, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_185, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_186, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_187, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_188, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_189, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_190, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_191, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_192, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_193, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_194, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_195, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_196, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_197, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_198, sizeof(u32_t) },
    { 0, TITAN_OD_TYPE_U32, TITAN_OD_ACCESS_RW, &s_od_obj_val_199, sizeof(u32_t) },
};

static const titan_od_entry_t s_od_entries[] = {
    { 0x1000, 1, &s_od_subentries[0] },
    { 0x1001, 1, &s_od_subentries[1] },
    { 0x1002, 1, &s_od_subentries[2] },
    { 0x1003, 1, &s_od_subentries[3] },
    { 0x1004, 1, &s_od_subentries[4] },
    { 0x1005, 1, &s_od_subentries[5] },
    { 0x1006, 1, &s_od_subentries[6] },
    { 0x1007, 1, &s_od_subentries[7] },
    { 0x1008, 1, &s_od_subentries[8] },
    { 0x1009, 1, &s_od_subentries[9] },
    { 0x100A, 1, &s_od_subentries[10] },
    { 0x100B, 1, &s_od_subentries[11] },
    { 0x100C, 1, &s_od_subentries[12] },
    { 0x100D, 1, &s_od_subentries[13] },
    { 0x100E, 1, &s_od_subentries[14] },
    { 0x100F, 1, &s_od_subentries[15] },
    { 0x1010, 1, &s_od_subentries[16] },
    { 0x1011, 1, &s_od_subentries[17] },
    { 0x1012, 1, &s_od_subentries[18] },
    { 0x1013, 1, &s_od_subentries[19] },
    { 0x1014, 1, &s_od_subentries[20] },
    { 0x1015, 1, &s_od_subentries[21] },
    { 0x1016, 1, &s_od_subentries[22] },
    { 0x1017, 1, &s_od_subentries[23] },
    { 0x1018, 1, &s_od_subentries[24] },
    { 0x1019, 1, &s_od_subentries[25] },
    { 0x101A, 1, &s_od_subentries[26] },
    { 0x101B, 1, &s_od_subentries[27] },
    { 0x101C, 1, &s_od_subentries[28] },
    { 0x101D, 1, &s_od_subentries[29] },
    { 0x101E, 1, &s_od_subentries[30] },
    { 0x101F, 1, &s_od_subentries[31] },
    { 0x1020, 1, &s_od_subentries[32] },
    { 0x1021, 1, &s_od_subentries[33] },
    { 0x1022, 1, &s_od_subentries[34] },
    { 0x1023, 1, &s_od_subentries[35] },
    { 0x1024, 1, &s_od_subentries[36] },
    { 0x1025, 1, &s_od_subentries[37] },
    { 0x1026, 1, &s_od_subentries[38] },
    { 0x1027, 1, &s_od_subentries[39] },
    { 0x1028, 1, &s_od_subentries[40] },
    { 0x1029, 1, &s_od_subentries[41] },
    { 0x102A, 1, &s_od_subentries[42] },
    { 0x102B, 1, &s_od_subentries[43] },
    { 0x102C, 1, &s_od_subentries[44] },
    { 0x102D, 1, &s_od_subentries[45] },
    { 0x102E, 1, &s_od_subentries[46] },
    { 0x102F, 1, &s_od_subentries[47] },
    { 0x1030, 1, &s_od_subentries[48] },
    { 0x1031, 1, &s_od_subentries[49] },
    { 0x1032, 1, &s_od_subentries[50] },
    { 0x1033, 1, &s_od_subentries[51] },
    { 0x1034, 1, &s_od_subentries[52] },
    { 0x1035, 1, &s_od_subentries[53] },
    { 0x1036, 1, &s_od_subentries[54] },
    { 0x1037, 1, &s_od_subentries[55] },
    { 0x1038, 1, &s_od_subentries[56] },
    { 0x1039, 1, &s_od_subentries[57] },
    { 0x103A, 1, &s_od_subentries[58] },
    { 0x103B, 1, &s_od_subentries[59] },
    { 0x103C, 1, &s_od_subentries[60] },
    { 0x103D, 1, &s_od_subentries[61] },
    { 0x103E, 1, &s_od_subentries[62] },
    { 0x103F, 1, &s_od_subentries[63] },
    { 0x1040, 1, &s_od_subentries[64] },
    { 0x1041, 1, &s_od_subentries[65] },
    { 0x1042, 1, &s_od_subentries[66] },
    { 0x1043, 1, &s_od_subentries[67] },
    { 0x1044, 1, &s_od_subentries[68] },
    { 0x1045, 1, &s_od_subentries[69] },
    { 0x1046, 1, &s_od_subentries[70] },
    { 0x1047, 1, &s_od_subentries[71] },
    { 0x1048, 1, &s_od_subentries[72] },
    { 0x1049, 1, &s_od_subentries[73] },
    { 0x104A, 1, &s_od_subentries[74] },
    { 0x104B, 1, &s_od_subentries[75] },
    { 0x104C, 1, &s_od_subentries[76] },
    { 0x104D, 1, &s_od_subentries[77] },
    { 0x104E, 1, &s_od_subentries[78] },
    { 0x104F, 1, &s_od_subentries[79] },
    { 0x1050, 1, &s_od_subentries[80] },
    { 0x1051, 1, &s_od_subentries[81] },
    { 0x1052, 1, &s_od_subentries[82] },
    { 0x1053, 1, &s_od_subentries[83] },
    { 0x1054, 1, &s_od_subentries[84] },
    { 0x1055, 1, &s_od_subentries[85] },
    { 0x1056, 1, &s_od_subentries[86] },
    { 0x1057, 1, &s_od_subentries[87] },
    { 0x1058, 1, &s_od_subentries[88] },
    { 0x1059, 1, &s_od_subentries[89] },
    { 0x105A, 1, &s_od_subentries[90] },
    { 0x105B, 1, &s_od_subentries[91] },
    { 0x105C, 1, &s_od_subentries[92] },
    { 0x105D, 1, &s_od_subentries[93] },
    { 0x105E, 1, &s_od_subentries[94] },
    { 0x105F, 1, &s_od_subentries[95] },
    { 0x1060, 1, &s_od_subentries[96] },
    { 0x1061, 1, &s_od_subentries[97] },
    { 0x1062, 1, &s_od_subentries[98] },
    { 0x1063, 1, &s_od_subentries[99] },
    { 0x1064, 1, &s_od_subentries[100] },
    { 0x1065, 1, &s_od_subentries[101] },
    { 0x1066, 1, &s_od_subentries[102] },
    { 0x1067, 1, &s_od_subentries[103] },
    { 0x1068, 1, &s_od_subentries[104] },
    { 0x1069, 1, &s_od_subentries[105] },
    { 0x106A, 1, &s_od_subentries[106] },
    { 0x106B, 1, &s_od_subentries[107] },
    { 0x106C, 1, &s_od_subentries[108] },
    { 0x106D, 1, &s_od_subentries[109] },
    { 0x106E, 1, &s_od_subentries[110] },
    { 0x106F, 1, &s_od_subentries[111] },
    { 0x1070, 1, &s_od_subentries[112] },
    { 0x1071, 1, &s_od_subentries[113] },
    { 0x1072, 1, &s_od_subentries[114] },
    { 0x1073, 1, &s_od_subentries[115] },
    { 0x1074, 1, &s_od_subentries[116] },
    { 0x1075, 1, &s_od_subentries[117] },
    { 0x1076, 1, &s_od_subentries[118] },
    { 0x1077, 1, &s_od_subentries[119] },
    { 0x1078, 1, &s_od_subentries[120] },
    { 0x1079, 1, &s_od_subentries[121] },
    { 0x107A, 1, &s_od_subentries[122] },
    { 0x107B, 1, &s_od_subentries[123] },
    { 0x107C, 1, &s_od_subentries[124] },
    { 0x107D, 1, &s_od_subentries[125] },
    { 0x107E, 1, &s_od_subentries[126] },
    { 0x107F, 1, &s_od_subentries[127] },
    { 0x1080, 1, &s_od_subentries[128] },
    { 0x1081, 1, &s_od_subentries[129] },
    { 0x1082, 1, &s_od_subentries[130] },
    { 0x1083, 1, &s_od_subentries[131] },
    { 0x1084, 1, &s_od_subentries[132] },
    { 0x1085, 1, &s_od_subentries[133] },
    { 0x1086, 1, &s_od_subentries[134] },
    { 0x1087, 1, &s_od_subentries[135] },
    { 0x1088, 1, &s_od_subentries[136] },
    { 0x1089, 1, &s_od_subentries[137] },
    { 0x108A, 1, &s_od_subentries[138] },
    { 0x108B, 1, &s_od_subentries[139] },
    { 0x108C, 1, &s_od_subentries[140] },
    { 0x108D, 1, &s_od_subentries[141] },
    { 0x108E, 1, &s_od_subentries[142] },
    { 0x108F, 1, &s_od_subentries[143] },
    { 0x1090, 1, &s_od_subentries[144] },
    { 0x1091, 1, &s_od_subentries[145] },
    { 0x1092, 1, &s_od_subentries[146] },
    { 0x1093, 1, &s_od_subentries[147] },
    { 0x1094, 1, &s_od_subentries[148] },
    { 0x1095, 1, &s_od_subentries[149] },
    { 0x1096, 1, &s_od_subentries[150] },
    { 0x1097, 1, &s_od_subentries[151] },
    { 0x1098, 1, &s_od_subentries[152] },
    { 0x1099, 1, &s_od_subentries[153] },
    { 0x109A, 1, &s_od_subentries[154] },
    { 0x109B, 1, &s_od_subentries[155] },
    { 0x109C, 1, &s_od_subentries[156] },
    { 0x109D, 1, &s_od_subentries[157] },
    { 0x109E, 1, &s_od_subentries[158] },
    { 0x109F, 1, &s_od_subentries[159] },
    { 0x10A0, 1, &s_od_subentries[160] },
    { 0x10A1, 1, &s_od_subentries[161] },
    { 0x10A2, 1, &s_od_subentries[162] },
    { 0x10A3, 1, &s_od_subentries[163] },
    { 0x10A4, 1, &s_od_subentries[164] },
    { 0x10A5, 1, &s_od_subentries[165] },
    { 0x10A6, 1, &s_od_subentries[166] },
    { 0x10A7, 1, &s_od_subentries[167] },
    { 0x10A8, 1, &s_od_subentries[168] },
    { 0x10A9, 1, &s_od_subentries[169] },
    { 0x10AA, 1, &s_od_subentries[170] },
    { 0x10AB, 1, &s_od_subentries[171] },
    { 0x10AC, 1, &s_od_subentries[172] },
    { 0x10AD, 1, &s_od_subentries[173] },
    { 0x10AE, 1, &s_od_subentries[174] },
    { 0x10AF, 1, &s_od_subentries[175] },
    { 0x10B0, 1, &s_od_subentries[176] },
    { 0x10B1, 1, &s_od_subentries[177] },
    { 0x10B2, 1, &s_od_subentries[178] },
    { 0x10B3, 1, &s_od_subentries[179] },
    { 0x10B4, 1, &s_od_subentries[180] },
    { 0x10B5, 1, &s_od_subentries[181] },
    { 0x10B6, 1, &s_od_subentries[182] },
    { 0x10B7, 1, &s_od_subentries[183] },
    { 0x10B8, 1, &s_od_subentries[184] },
    { 0x10B9, 1, &s_od_subentries[185] },
    { 0x10BA, 1, &s_od_subentries[186] },
    { 0x10BB, 1, &s_od_subentries[187] },
    { 0x10BC, 1, &s_od_subentries[188] },
    { 0x10BD, 1, &s_od_subentries[189] },
    { 0x10BE, 1, &s_od_subentries[190] },
    { 0x10BF, 1, &s_od_subentries[191] },
    { 0x10C0, 1, &s_od_subentries[192] },
    { 0x10C1, 1, &s_od_subentries[193] },
    { 0x10C2, 1, &s_od_subentries[194] },
    { 0x10C3, 1, &s_od_subentries[195] },
    { 0x10C4, 1, &s_od_subentries[196] },
    { 0x10C5, 1, &s_od_subentries[197] },
    { 0x10C6, 1, &s_od_subentries[198] },
    { 0x10C7, 1, &s_od_subentries[199] },
};

const titan_od_entry_t* titan_od_get_default_table(mem_size_t *count)
{
    if (count) *count = sizeof(s_od_entries) / sizeof(s_od_entries[0]);
    return s_od_entries;
}
