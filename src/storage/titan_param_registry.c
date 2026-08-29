/**
 * @file titan_param_registry.c
 * @brief Parameter Schema Definitions, Min/Max Clamping and Change Tracking
 */

#include "storage/titan_param_registry.h"
#include "core/titan_string.h"
#include "core/titan_defs.h"
#include <string.h>

static f32_t s_param_val_0;
static f32_t s_param_val_1;
static f32_t s_param_val_2;
static f32_t s_param_val_3;
static f32_t s_param_val_4;
static f32_t s_param_val_5;
static f32_t s_param_val_6;
static f32_t s_param_val_7;
static f32_t s_param_val_8;
static f32_t s_param_val_9;
static f32_t s_param_val_10;
static f32_t s_param_val_11;
static f32_t s_param_val_12;
static f32_t s_param_val_13;
static f32_t s_param_val_14;
static f32_t s_param_val_15;
static f32_t s_param_val_16;
static f32_t s_param_val_17;
static f32_t s_param_val_18;
static f32_t s_param_val_19;
static f32_t s_param_val_20;
static f32_t s_param_val_21;
static f32_t s_param_val_22;
static f32_t s_param_val_23;
static f32_t s_param_val_24;
static f32_t s_param_val_25;
static f32_t s_param_val_26;
static f32_t s_param_val_27;
static f32_t s_param_val_28;
static f32_t s_param_val_29;
static f32_t s_param_val_30;
static f32_t s_param_val_31;
static f32_t s_param_val_32;
static f32_t s_param_val_33;
static f32_t s_param_val_34;
static f32_t s_param_val_35;
static f32_t s_param_val_36;
static f32_t s_param_val_37;
static f32_t s_param_val_38;
static f32_t s_param_val_39;
static f32_t s_param_val_40;
static f32_t s_param_val_41;
static f32_t s_param_val_42;
static f32_t s_param_val_43;
static f32_t s_param_val_44;
static f32_t s_param_val_45;
static f32_t s_param_val_46;
static f32_t s_param_val_47;
static f32_t s_param_val_48;
static f32_t s_param_val_49;
static f32_t s_param_val_50;
static f32_t s_param_val_51;
static f32_t s_param_val_52;
static f32_t s_param_val_53;
static f32_t s_param_val_54;
static f32_t s_param_val_55;
static f32_t s_param_val_56;
static f32_t s_param_val_57;
static f32_t s_param_val_58;
static f32_t s_param_val_59;
static f32_t s_param_val_60;
static f32_t s_param_val_61;
static f32_t s_param_val_62;
static f32_t s_param_val_63;
static f32_t s_param_val_64;
static f32_t s_param_val_65;
static f32_t s_param_val_66;
static f32_t s_param_val_67;
static f32_t s_param_val_68;
static f32_t s_param_val_69;
static f32_t s_param_val_70;
static f32_t s_param_val_71;
static f32_t s_param_val_72;
static f32_t s_param_val_73;
static f32_t s_param_val_74;
static f32_t s_param_val_75;
static f32_t s_param_val_76;
static f32_t s_param_val_77;
static f32_t s_param_val_78;
static f32_t s_param_val_79;
static f32_t s_param_val_80;
static f32_t s_param_val_81;
static f32_t s_param_val_82;
static f32_t s_param_val_83;
static f32_t s_param_val_84;
static f32_t s_param_val_85;
static f32_t s_param_val_86;
static f32_t s_param_val_87;
static f32_t s_param_val_88;
static f32_t s_param_val_89;
static f32_t s_param_val_90;
static f32_t s_param_val_91;
static f32_t s_param_val_92;
static f32_t s_param_val_93;
static f32_t s_param_val_94;
static f32_t s_param_val_95;
static f32_t s_param_val_96;
static f32_t s_param_val_97;
static f32_t s_param_val_98;
static f32_t s_param_val_99;
static f32_t s_param_val_100;
static f32_t s_param_val_101;
static f32_t s_param_val_102;
static f32_t s_param_val_103;
static f32_t s_param_val_104;
static f32_t s_param_val_105;
static f32_t s_param_val_106;
static f32_t s_param_val_107;
static f32_t s_param_val_108;
static f32_t s_param_val_109;
static f32_t s_param_val_110;
static f32_t s_param_val_111;
static f32_t s_param_val_112;
static f32_t s_param_val_113;
static f32_t s_param_val_114;
static f32_t s_param_val_115;
static f32_t s_param_val_116;
static f32_t s_param_val_117;
static f32_t s_param_val_118;
static f32_t s_param_val_119;
static f32_t s_param_val_120;
static f32_t s_param_val_121;
static f32_t s_param_val_122;
static f32_t s_param_val_123;
static f32_t s_param_val_124;
static f32_t s_param_val_125;
static f32_t s_param_val_126;
static f32_t s_param_val_127;
static f32_t s_param_val_128;
static f32_t s_param_val_129;
static f32_t s_param_val_130;
static f32_t s_param_val_131;
static f32_t s_param_val_132;
static f32_t s_param_val_133;
static f32_t s_param_val_134;
static f32_t s_param_val_135;
static f32_t s_param_val_136;
static f32_t s_param_val_137;
static f32_t s_param_val_138;
static f32_t s_param_val_139;
static f32_t s_param_val_140;
static f32_t s_param_val_141;
static f32_t s_param_val_142;
static f32_t s_param_val_143;
static f32_t s_param_val_144;
static f32_t s_param_val_145;
static f32_t s_param_val_146;
static f32_t s_param_val_147;
static f32_t s_param_val_148;
static f32_t s_param_val_149;
static f32_t s_param_val_150;
static f32_t s_param_val_151;
static f32_t s_param_val_152;
static f32_t s_param_val_153;
static f32_t s_param_val_154;
static f32_t s_param_val_155;
static f32_t s_param_val_156;
static f32_t s_param_val_157;
static f32_t s_param_val_158;
static f32_t s_param_val_159;
static f32_t s_param_val_160;
static f32_t s_param_val_161;
static f32_t s_param_val_162;
static f32_t s_param_val_163;
static f32_t s_param_val_164;
static f32_t s_param_val_165;
static f32_t s_param_val_166;
static f32_t s_param_val_167;
static f32_t s_param_val_168;
static f32_t s_param_val_169;
static f32_t s_param_val_170;
static f32_t s_param_val_171;
static f32_t s_param_val_172;
static f32_t s_param_val_173;
static f32_t s_param_val_174;
static f32_t s_param_val_175;
static f32_t s_param_val_176;
static f32_t s_param_val_177;
static f32_t s_param_val_178;
static f32_t s_param_val_179;
static f32_t s_param_val_180;
static f32_t s_param_val_181;
static f32_t s_param_val_182;
static f32_t s_param_val_183;
static f32_t s_param_val_184;
static f32_t s_param_val_185;
static f32_t s_param_val_186;
static f32_t s_param_val_187;
static f32_t s_param_val_188;
static f32_t s_param_val_189;
static f32_t s_param_val_190;
static f32_t s_param_val_191;
static f32_t s_param_val_192;
static f32_t s_param_val_193;
static f32_t s_param_val_194;
static f32_t s_param_val_195;
static f32_t s_param_val_196;
static f32_t s_param_val_197;
static f32_t s_param_val_198;
static f32_t s_param_val_199;
static f32_t s_param_val_200;
static f32_t s_param_val_201;
static f32_t s_param_val_202;
static f32_t s_param_val_203;
static f32_t s_param_val_204;
static f32_t s_param_val_205;
static f32_t s_param_val_206;
static f32_t s_param_val_207;
static f32_t s_param_val_208;
static f32_t s_param_val_209;
static f32_t s_param_val_210;
static f32_t s_param_val_211;
static f32_t s_param_val_212;
static f32_t s_param_val_213;
static f32_t s_param_val_214;
static f32_t s_param_val_215;
static f32_t s_param_val_216;
static f32_t s_param_val_217;
static f32_t s_param_val_218;
static f32_t s_param_val_219;
static f32_t s_param_val_220;
static f32_t s_param_val_221;
static f32_t s_param_val_222;
static f32_t s_param_val_223;
static f32_t s_param_val_224;
static f32_t s_param_val_225;
static f32_t s_param_val_226;
static f32_t s_param_val_227;
static f32_t s_param_val_228;
static f32_t s_param_val_229;
static f32_t s_param_val_230;
static f32_t s_param_val_231;
static f32_t s_param_val_232;
static f32_t s_param_val_233;
static f32_t s_param_val_234;
static f32_t s_param_val_235;
static f32_t s_param_val_236;
static f32_t s_param_val_237;
static f32_t s_param_val_238;
static f32_t s_param_val_239;
static f32_t s_param_val_240;
static f32_t s_param_val_241;
static f32_t s_param_val_242;
static f32_t s_param_val_243;
static f32_t s_param_val_244;
static f32_t s_param_val_245;
static f32_t s_param_val_246;
static f32_t s_param_val_247;
static f32_t s_param_val_248;
static f32_t s_param_val_249;
static f32_t s_param_val_250;
static f32_t s_param_val_251;
static f32_t s_param_val_252;
static f32_t s_param_val_253;
static f32_t s_param_val_254;
static f32_t s_param_val_255;
static f32_t s_param_val_256;
static f32_t s_param_val_257;
static f32_t s_param_val_258;
static f32_t s_param_val_259;
static f32_t s_param_val_260;
static f32_t s_param_val_261;
static f32_t s_param_val_262;
static f32_t s_param_val_263;
static f32_t s_param_val_264;
static f32_t s_param_val_265;
static f32_t s_param_val_266;
static f32_t s_param_val_267;
static f32_t s_param_val_268;
static f32_t s_param_val_269;
static f32_t s_param_val_270;
static f32_t s_param_val_271;
static f32_t s_param_val_272;
static f32_t s_param_val_273;
static f32_t s_param_val_274;
static f32_t s_param_val_275;
static f32_t s_param_val_276;
static f32_t s_param_val_277;
static f32_t s_param_val_278;
static f32_t s_param_val_279;
static f32_t s_param_val_280;
static f32_t s_param_val_281;
static f32_t s_param_val_282;
static f32_t s_param_val_283;
static f32_t s_param_val_284;
static f32_t s_param_val_285;
static f32_t s_param_val_286;
static f32_t s_param_val_287;
static f32_t s_param_val_288;
static f32_t s_param_val_289;
static f32_t s_param_val_290;
static f32_t s_param_val_291;
static f32_t s_param_val_292;
static f32_t s_param_val_293;
static f32_t s_param_val_294;
static f32_t s_param_val_295;
static f32_t s_param_val_296;
static f32_t s_param_val_297;
static f32_t s_param_val_298;
static f32_t s_param_val_299;
static f32_t s_param_val_300;
static f32_t s_param_val_301;
static f32_t s_param_val_302;
static f32_t s_param_val_303;
static f32_t s_param_val_304;
static f32_t s_param_val_305;
static f32_t s_param_val_306;
static f32_t s_param_val_307;
static f32_t s_param_val_308;
static f32_t s_param_val_309;
static f32_t s_param_val_310;
static f32_t s_param_val_311;
static f32_t s_param_val_312;
static f32_t s_param_val_313;
static f32_t s_param_val_314;
static f32_t s_param_val_315;
static f32_t s_param_val_316;
static f32_t s_param_val_317;
static f32_t s_param_val_318;
static f32_t s_param_val_319;
static f32_t s_param_val_320;
static f32_t s_param_val_321;
static f32_t s_param_val_322;
static f32_t s_param_val_323;
static f32_t s_param_val_324;
static f32_t s_param_val_325;
static f32_t s_param_val_326;
static f32_t s_param_val_327;
static f32_t s_param_val_328;
static f32_t s_param_val_329;
static f32_t s_param_val_330;
static f32_t s_param_val_331;
static f32_t s_param_val_332;
static f32_t s_param_val_333;
static f32_t s_param_val_334;
static f32_t s_param_val_335;
static f32_t s_param_val_336;
static f32_t s_param_val_337;
static f32_t s_param_val_338;
static f32_t s_param_val_339;
static f32_t s_param_val_340;
static f32_t s_param_val_341;
static f32_t s_param_val_342;
static f32_t s_param_val_343;
static f32_t s_param_val_344;
static f32_t s_param_val_345;
static f32_t s_param_val_346;
static f32_t s_param_val_347;
static f32_t s_param_val_348;
static f32_t s_param_val_349;

static titan_param_entry_t s_param_table[TITAN_PARAM_COUNT] = {
    { 0, "NAV_CONFIG_000", TITAN_PARAM_TYPE_F32, -50.0f, 150.0f, 50.0f, &s_param_val_0, FALSE },
    { 1, "NAV_CONFIG_001", TITAN_PARAM_TYPE_F32, -49.5f, 150.5f, 50.5f, &s_param_val_1, FALSE },
    { 2, "NAV_CONFIG_002", TITAN_PARAM_TYPE_F32, -49.0f, 151.0f, 51.0f, &s_param_val_2, FALSE },
    { 3, "NAV_CONFIG_003", TITAN_PARAM_TYPE_F32, -48.5f, 151.5f, 51.5f, &s_param_val_3, FALSE },
    { 4, "NAV_CONFIG_004", TITAN_PARAM_TYPE_F32, -48.0f, 152.0f, 52.0f, &s_param_val_4, FALSE },
    { 5, "NAV_CONFIG_005", TITAN_PARAM_TYPE_F32, -47.5f, 152.5f, 52.5f, &s_param_val_5, FALSE },
    { 6, "NAV_CONFIG_006", TITAN_PARAM_TYPE_F32, -47.0f, 153.0f, 53.0f, &s_param_val_6, FALSE },
    { 7, "NAV_CONFIG_007", TITAN_PARAM_TYPE_F32, -46.5f, 153.5f, 53.5f, &s_param_val_7, FALSE },
    { 8, "NAV_CONFIG_008", TITAN_PARAM_TYPE_F32, -46.0f, 154.0f, 54.0f, &s_param_val_8, FALSE },
    { 9, "NAV_CONFIG_009", TITAN_PARAM_TYPE_F32, -45.5f, 154.5f, 54.5f, &s_param_val_9, FALSE },
    { 10, "NAV_CONFIG_010", TITAN_PARAM_TYPE_F32, -45.0f, 155.0f, 55.0f, &s_param_val_10, FALSE },
    { 11, "NAV_CONFIG_011", TITAN_PARAM_TYPE_F32, -44.5f, 155.5f, 55.5f, &s_param_val_11, FALSE },
    { 12, "NAV_CONFIG_012", TITAN_PARAM_TYPE_F32, -44.0f, 156.0f, 56.0f, &s_param_val_12, FALSE },
    { 13, "NAV_CONFIG_013", TITAN_PARAM_TYPE_F32, -43.5f, 156.5f, 56.5f, &s_param_val_13, FALSE },
    { 14, "NAV_CONFIG_014", TITAN_PARAM_TYPE_F32, -43.0f, 157.0f, 57.0f, &s_param_val_14, FALSE },
    { 15, "NAV_CONFIG_015", TITAN_PARAM_TYPE_F32, -42.5f, 157.5f, 57.5f, &s_param_val_15, FALSE },
    { 16, "NAV_CONFIG_016", TITAN_PARAM_TYPE_F32, -42.0f, 158.0f, 58.0f, &s_param_val_16, FALSE },
    { 17, "NAV_CONFIG_017", TITAN_PARAM_TYPE_F32, -41.5f, 158.5f, 58.5f, &s_param_val_17, FALSE },
    { 18, "NAV_CONFIG_018", TITAN_PARAM_TYPE_F32, -41.0f, 159.0f, 59.0f, &s_param_val_18, FALSE },
    { 19, "NAV_CONFIG_019", TITAN_PARAM_TYPE_F32, -40.5f, 159.5f, 59.5f, &s_param_val_19, FALSE },
    { 20, "NAV_CONFIG_020", TITAN_PARAM_TYPE_F32, -40.0f, 160.0f, 60.0f, &s_param_val_20, FALSE },
    { 21, "NAV_CONFIG_021", TITAN_PARAM_TYPE_F32, -39.5f, 160.5f, 60.5f, &s_param_val_21, FALSE },
    { 22, "NAV_CONFIG_022", TITAN_PARAM_TYPE_F32, -39.0f, 161.0f, 61.0f, &s_param_val_22, FALSE },
    { 23, "NAV_CONFIG_023", TITAN_PARAM_TYPE_F32, -38.5f, 161.5f, 61.5f, &s_param_val_23, FALSE },
    { 24, "NAV_CONFIG_024", TITAN_PARAM_TYPE_F32, -38.0f, 162.0f, 62.0f, &s_param_val_24, FALSE },
    { 25, "NAV_CONFIG_025", TITAN_PARAM_TYPE_F32, -37.5f, 162.5f, 62.5f, &s_param_val_25, FALSE },
    { 26, "NAV_CONFIG_026", TITAN_PARAM_TYPE_F32, -37.0f, 163.0f, 63.0f, &s_param_val_26, FALSE },
    { 27, "NAV_CONFIG_027", TITAN_PARAM_TYPE_F32, -36.5f, 163.5f, 63.5f, &s_param_val_27, FALSE },
    { 28, "NAV_CONFIG_028", TITAN_PARAM_TYPE_F32, -36.0f, 164.0f, 64.0f, &s_param_val_28, FALSE },
    { 29, "NAV_CONFIG_029", TITAN_PARAM_TYPE_F32, -35.5f, 164.5f, 64.5f, &s_param_val_29, FALSE },
    { 30, "NAV_CONFIG_030", TITAN_PARAM_TYPE_F32, -35.0f, 165.0f, 65.0f, &s_param_val_30, FALSE },
    { 31, "NAV_CONFIG_031", TITAN_PARAM_TYPE_F32, -34.5f, 165.5f, 65.5f, &s_param_val_31, FALSE },
    { 32, "NAV_CONFIG_032", TITAN_PARAM_TYPE_F32, -34.0f, 166.0f, 66.0f, &s_param_val_32, FALSE },
    { 33, "NAV_CONFIG_033", TITAN_PARAM_TYPE_F32, -33.5f, 166.5f, 66.5f, &s_param_val_33, FALSE },
    { 34, "NAV_CONFIG_034", TITAN_PARAM_TYPE_F32, -33.0f, 167.0f, 67.0f, &s_param_val_34, FALSE },
    { 35, "ATT_CONFIG_035", TITAN_PARAM_TYPE_F32, -32.5f, 167.5f, 67.5f, &s_param_val_35, FALSE },
    { 36, "ATT_CONFIG_036", TITAN_PARAM_TYPE_F32, -32.0f, 168.0f, 68.0f, &s_param_val_36, FALSE },
    { 37, "ATT_CONFIG_037", TITAN_PARAM_TYPE_F32, -31.5f, 168.5f, 68.5f, &s_param_val_37, FALSE },
    { 38, "ATT_CONFIG_038", TITAN_PARAM_TYPE_F32, -31.0f, 169.0f, 69.0f, &s_param_val_38, FALSE },
    { 39, "ATT_CONFIG_039", TITAN_PARAM_TYPE_F32, -30.5f, 169.5f, 69.5f, &s_param_val_39, FALSE },
    { 40, "ATT_CONFIG_040", TITAN_PARAM_TYPE_F32, -30.0f, 170.0f, 70.0f, &s_param_val_40, FALSE },
    { 41, "ATT_CONFIG_041", TITAN_PARAM_TYPE_F32, -29.5f, 170.5f, 70.5f, &s_param_val_41, FALSE },
    { 42, "ATT_CONFIG_042", TITAN_PARAM_TYPE_F32, -29.0f, 171.0f, 71.0f, &s_param_val_42, FALSE },
    { 43, "ATT_CONFIG_043", TITAN_PARAM_TYPE_F32, -28.5f, 171.5f, 71.5f, &s_param_val_43, FALSE },
    { 44, "ATT_CONFIG_044", TITAN_PARAM_TYPE_F32, -28.0f, 172.0f, 72.0f, &s_param_val_44, FALSE },
    { 45, "ATT_CONFIG_045", TITAN_PARAM_TYPE_F32, -27.5f, 172.5f, 72.5f, &s_param_val_45, FALSE },
    { 46, "ATT_CONFIG_046", TITAN_PARAM_TYPE_F32, -27.0f, 173.0f, 73.0f, &s_param_val_46, FALSE },
    { 47, "ATT_CONFIG_047", TITAN_PARAM_TYPE_F32, -26.5f, 173.5f, 73.5f, &s_param_val_47, FALSE },
    { 48, "ATT_CONFIG_048", TITAN_PARAM_TYPE_F32, -26.0f, 174.0f, 74.0f, &s_param_val_48, FALSE },
    { 49, "ATT_CONFIG_049", TITAN_PARAM_TYPE_F32, -25.5f, 174.5f, 74.5f, &s_param_val_49, FALSE },
    { 50, "ATT_CONFIG_050", TITAN_PARAM_TYPE_F32, -25.0f, 175.0f, 75.0f, &s_param_val_50, FALSE },
    { 51, "ATT_CONFIG_051", TITAN_PARAM_TYPE_F32, -24.5f, 175.5f, 75.5f, &s_param_val_51, FALSE },
    { 52, "ATT_CONFIG_052", TITAN_PARAM_TYPE_F32, -24.0f, 176.0f, 76.0f, &s_param_val_52, FALSE },
    { 53, "ATT_CONFIG_053", TITAN_PARAM_TYPE_F32, -23.5f, 176.5f, 76.5f, &s_param_val_53, FALSE },
    { 54, "ATT_CONFIG_054", TITAN_PARAM_TYPE_F32, -23.0f, 177.0f, 77.0f, &s_param_val_54, FALSE },
    { 55, "ATT_CONFIG_055", TITAN_PARAM_TYPE_F32, -22.5f, 177.5f, 77.5f, &s_param_val_55, FALSE },
    { 56, "ATT_CONFIG_056", TITAN_PARAM_TYPE_F32, -22.0f, 178.0f, 78.0f, &s_param_val_56, FALSE },
    { 57, "ATT_CONFIG_057", TITAN_PARAM_TYPE_F32, -21.5f, 178.5f, 78.5f, &s_param_val_57, FALSE },
    { 58, "ATT_CONFIG_058", TITAN_PARAM_TYPE_F32, -21.0f, 179.0f, 79.0f, &s_param_val_58, FALSE },
    { 59, "ATT_CONFIG_059", TITAN_PARAM_TYPE_F32, -20.5f, 179.5f, 79.5f, &s_param_val_59, FALSE },
    { 60, "ATT_CONFIG_060", TITAN_PARAM_TYPE_F32, -20.0f, 180.0f, 80.0f, &s_param_val_60, FALSE },
    { 61, "ATT_CONFIG_061", TITAN_PARAM_TYPE_F32, -19.5f, 180.5f, 80.5f, &s_param_val_61, FALSE },
    { 62, "ATT_CONFIG_062", TITAN_PARAM_TYPE_F32, -19.0f, 181.0f, 81.0f, &s_param_val_62, FALSE },
    { 63, "ATT_CONFIG_063", TITAN_PARAM_TYPE_F32, -18.5f, 181.5f, 81.5f, &s_param_val_63, FALSE },
    { 64, "ATT_CONFIG_064", TITAN_PARAM_TYPE_F32, -18.0f, 182.0f, 82.0f, &s_param_val_64, FALSE },
    { 65, "ATT_CONFIG_065", TITAN_PARAM_TYPE_F32, -17.5f, 182.5f, 82.5f, &s_param_val_65, FALSE },
    { 66, "ATT_CONFIG_066", TITAN_PARAM_TYPE_F32, -17.0f, 183.0f, 83.0f, &s_param_val_66, FALSE },
    { 67, "ATT_CONFIG_067", TITAN_PARAM_TYPE_F32, -16.5f, 183.5f, 83.5f, &s_param_val_67, FALSE },
    { 68, "ATT_CONFIG_068", TITAN_PARAM_TYPE_F32, -16.0f, 184.0f, 84.0f, &s_param_val_68, FALSE },
    { 69, "ATT_CONFIG_069", TITAN_PARAM_TYPE_F32, -15.5f, 184.5f, 84.5f, &s_param_val_69, FALSE },
    { 70, "POS_CONFIG_070", TITAN_PARAM_TYPE_F32, -15.0f, 185.0f, 85.0f, &s_param_val_70, FALSE },
    { 71, "POS_CONFIG_071", TITAN_PARAM_TYPE_F32, -14.5f, 185.5f, 85.5f, &s_param_val_71, FALSE },
    { 72, "POS_CONFIG_072", TITAN_PARAM_TYPE_F32, -14.0f, 186.0f, 86.0f, &s_param_val_72, FALSE },
    { 73, "POS_CONFIG_073", TITAN_PARAM_TYPE_F32, -13.5f, 186.5f, 86.5f, &s_param_val_73, FALSE },
    { 74, "POS_CONFIG_074", TITAN_PARAM_TYPE_F32, -13.0f, 187.0f, 87.0f, &s_param_val_74, FALSE },
    { 75, "POS_CONFIG_075", TITAN_PARAM_TYPE_F32, -12.5f, 187.5f, 87.5f, &s_param_val_75, FALSE },
    { 76, "POS_CONFIG_076", TITAN_PARAM_TYPE_F32, -12.0f, 188.0f, 88.0f, &s_param_val_76, FALSE },
    { 77, "POS_CONFIG_077", TITAN_PARAM_TYPE_F32, -11.5f, 188.5f, 88.5f, &s_param_val_77, FALSE },
    { 78, "POS_CONFIG_078", TITAN_PARAM_TYPE_F32, -11.0f, 189.0f, 89.0f, &s_param_val_78, FALSE },
    { 79, "POS_CONFIG_079", TITAN_PARAM_TYPE_F32, -10.5f, 189.5f, 89.5f, &s_param_val_79, FALSE },
    { 80, "POS_CONFIG_080", TITAN_PARAM_TYPE_F32, -10.0f, 190.0f, 90.0f, &s_param_val_80, FALSE },
    { 81, "POS_CONFIG_081", TITAN_PARAM_TYPE_F32, -9.5f, 190.5f, 90.5f, &s_param_val_81, FALSE },
    { 82, "POS_CONFIG_082", TITAN_PARAM_TYPE_F32, -9.0f, 191.0f, 91.0f, &s_param_val_82, FALSE },
    { 83, "POS_CONFIG_083", TITAN_PARAM_TYPE_F32, -8.5f, 191.5f, 91.5f, &s_param_val_83, FALSE },
    { 84, "POS_CONFIG_084", TITAN_PARAM_TYPE_F32, -8.0f, 192.0f, 92.0f, &s_param_val_84, FALSE },
    { 85, "POS_CONFIG_085", TITAN_PARAM_TYPE_F32, -7.5f, 192.5f, 92.5f, &s_param_val_85, FALSE },
    { 86, "POS_CONFIG_086", TITAN_PARAM_TYPE_F32, -7.0f, 193.0f, 93.0f, &s_param_val_86, FALSE },
    { 87, "POS_CONFIG_087", TITAN_PARAM_TYPE_F32, -6.5f, 193.5f, 93.5f, &s_param_val_87, FALSE },
    { 88, "POS_CONFIG_088", TITAN_PARAM_TYPE_F32, -6.0f, 194.0f, 94.0f, &s_param_val_88, FALSE },
    { 89, "POS_CONFIG_089", TITAN_PARAM_TYPE_F32, -5.5f, 194.5f, 94.5f, &s_param_val_89, FALSE },
    { 90, "POS_CONFIG_090", TITAN_PARAM_TYPE_F32, -5.0f, 195.0f, 95.0f, &s_param_val_90, FALSE },
    { 91, "POS_CONFIG_091", TITAN_PARAM_TYPE_F32, -4.5f, 195.5f, 95.5f, &s_param_val_91, FALSE },
    { 92, "POS_CONFIG_092", TITAN_PARAM_TYPE_F32, -4.0f, 196.0f, 96.0f, &s_param_val_92, FALSE },
    { 93, "POS_CONFIG_093", TITAN_PARAM_TYPE_F32, -3.5f, 196.5f, 96.5f, &s_param_val_93, FALSE },
    { 94, "POS_CONFIG_094", TITAN_PARAM_TYPE_F32, -3.0f, 197.0f, 97.0f, &s_param_val_94, FALSE },
    { 95, "POS_CONFIG_095", TITAN_PARAM_TYPE_F32, -2.5f, 197.5f, 97.5f, &s_param_val_95, FALSE },
    { 96, "POS_CONFIG_096", TITAN_PARAM_TYPE_F32, -2.0f, 198.0f, 98.0f, &s_param_val_96, FALSE },
    { 97, "POS_CONFIG_097", TITAN_PARAM_TYPE_F32, -1.5f, 198.5f, 98.5f, &s_param_val_97, FALSE },
    { 98, "POS_CONFIG_098", TITAN_PARAM_TYPE_F32, -1.0f, 199.0f, 99.0f, &s_param_val_98, FALSE },
    { 99, "POS_CONFIG_099", TITAN_PARAM_TYPE_F32, -0.5f, 199.5f, 99.5f, &s_param_val_99, FALSE },
    { 100, "POS_CONFIG_100", TITAN_PARAM_TYPE_F32, 0.0f, 200.0f, 100.0f, &s_param_val_100, FALSE },
    { 101, "POS_CONFIG_101", TITAN_PARAM_TYPE_F32, 0.5f, 200.5f, 100.5f, &s_param_val_101, FALSE },
    { 102, "POS_CONFIG_102", TITAN_PARAM_TYPE_F32, 1.0f, 201.0f, 101.0f, &s_param_val_102, FALSE },
    { 103, "POS_CONFIG_103", TITAN_PARAM_TYPE_F32, 1.5f, 201.5f, 101.5f, &s_param_val_103, FALSE },
    { 104, "POS_CONFIG_104", TITAN_PARAM_TYPE_F32, 2.0f, 202.0f, 102.0f, &s_param_val_104, FALSE },
    { 105, "BAT_CONFIG_105", TITAN_PARAM_TYPE_F32, 2.5f, 202.5f, 102.5f, &s_param_val_105, FALSE },
    { 106, "BAT_CONFIG_106", TITAN_PARAM_TYPE_F32, 3.0f, 203.0f, 103.0f, &s_param_val_106, FALSE },
    { 107, "BAT_CONFIG_107", TITAN_PARAM_TYPE_F32, 3.5f, 203.5f, 103.5f, &s_param_val_107, FALSE },
    { 108, "BAT_CONFIG_108", TITAN_PARAM_TYPE_F32, 4.0f, 204.0f, 104.0f, &s_param_val_108, FALSE },
    { 109, "BAT_CONFIG_109", TITAN_PARAM_TYPE_F32, 4.5f, 204.5f, 104.5f, &s_param_val_109, FALSE },
    { 110, "BAT_CONFIG_110", TITAN_PARAM_TYPE_F32, 5.0f, 205.0f, 105.0f, &s_param_val_110, FALSE },
    { 111, "BAT_CONFIG_111", TITAN_PARAM_TYPE_F32, 5.5f, 205.5f, 105.5f, &s_param_val_111, FALSE },
    { 112, "BAT_CONFIG_112", TITAN_PARAM_TYPE_F32, 6.0f, 206.0f, 106.0f, &s_param_val_112, FALSE },
    { 113, "BAT_CONFIG_113", TITAN_PARAM_TYPE_F32, 6.5f, 206.5f, 106.5f, &s_param_val_113, FALSE },
    { 114, "BAT_CONFIG_114", TITAN_PARAM_TYPE_F32, 7.0f, 207.0f, 107.0f, &s_param_val_114, FALSE },
    { 115, "BAT_CONFIG_115", TITAN_PARAM_TYPE_F32, 7.5f, 207.5f, 107.5f, &s_param_val_115, FALSE },
    { 116, "BAT_CONFIG_116", TITAN_PARAM_TYPE_F32, 8.0f, 208.0f, 108.0f, &s_param_val_116, FALSE },
    { 117, "BAT_CONFIG_117", TITAN_PARAM_TYPE_F32, 8.5f, 208.5f, 108.5f, &s_param_val_117, FALSE },
    { 118, "BAT_CONFIG_118", TITAN_PARAM_TYPE_F32, 9.0f, 209.0f, 109.0f, &s_param_val_118, FALSE },
    { 119, "BAT_CONFIG_119", TITAN_PARAM_TYPE_F32, 9.5f, 209.5f, 109.5f, &s_param_val_119, FALSE },
    { 120, "BAT_CONFIG_120", TITAN_PARAM_TYPE_F32, 10.0f, 210.0f, 110.0f, &s_param_val_120, FALSE },
    { 121, "BAT_CONFIG_121", TITAN_PARAM_TYPE_F32, 10.5f, 210.5f, 110.5f, &s_param_val_121, FALSE },
    { 122, "BAT_CONFIG_122", TITAN_PARAM_TYPE_F32, 11.0f, 211.0f, 111.0f, &s_param_val_122, FALSE },
    { 123, "BAT_CONFIG_123", TITAN_PARAM_TYPE_F32, 11.5f, 211.5f, 111.5f, &s_param_val_123, FALSE },
    { 124, "BAT_CONFIG_124", TITAN_PARAM_TYPE_F32, 12.0f, 212.0f, 112.0f, &s_param_val_124, FALSE },
    { 125, "BAT_CONFIG_125", TITAN_PARAM_TYPE_F32, 12.5f, 212.5f, 112.5f, &s_param_val_125, FALSE },
    { 126, "BAT_CONFIG_126", TITAN_PARAM_TYPE_F32, 13.0f, 213.0f, 113.0f, &s_param_val_126, FALSE },
    { 127, "BAT_CONFIG_127", TITAN_PARAM_TYPE_F32, 13.5f, 213.5f, 113.5f, &s_param_val_127, FALSE },
    { 128, "BAT_CONFIG_128", TITAN_PARAM_TYPE_F32, 14.0f, 214.0f, 114.0f, &s_param_val_128, FALSE },
    { 129, "BAT_CONFIG_129", TITAN_PARAM_TYPE_F32, 14.5f, 214.5f, 114.5f, &s_param_val_129, FALSE },
    { 130, "BAT_CONFIG_130", TITAN_PARAM_TYPE_F32, 15.0f, 215.0f, 115.0f, &s_param_val_130, FALSE },
    { 131, "BAT_CONFIG_131", TITAN_PARAM_TYPE_F32, 15.5f, 215.5f, 115.5f, &s_param_val_131, FALSE },
    { 132, "BAT_CONFIG_132", TITAN_PARAM_TYPE_F32, 16.0f, 216.0f, 116.0f, &s_param_val_132, FALSE },
    { 133, "BAT_CONFIG_133", TITAN_PARAM_TYPE_F32, 16.5f, 216.5f, 116.5f, &s_param_val_133, FALSE },
    { 134, "BAT_CONFIG_134", TITAN_PARAM_TYPE_F32, 17.0f, 217.0f, 117.0f, &s_param_val_134, FALSE },
    { 135, "BAT_CONFIG_135", TITAN_PARAM_TYPE_F32, 17.5f, 217.5f, 117.5f, &s_param_val_135, FALSE },
    { 136, "BAT_CONFIG_136", TITAN_PARAM_TYPE_F32, 18.0f, 218.0f, 118.0f, &s_param_val_136, FALSE },
    { 137, "BAT_CONFIG_137", TITAN_PARAM_TYPE_F32, 18.5f, 218.5f, 118.5f, &s_param_val_137, FALSE },
    { 138, "BAT_CONFIG_138", TITAN_PARAM_TYPE_F32, 19.0f, 219.0f, 119.0f, &s_param_val_138, FALSE },
    { 139, "BAT_CONFIG_139", TITAN_PARAM_TYPE_F32, 19.5f, 219.5f, 119.5f, &s_param_val_139, FALSE },
    { 140, "MOT_CONFIG_140", TITAN_PARAM_TYPE_F32, 20.0f, 220.0f, 120.0f, &s_param_val_140, FALSE },
    { 141, "MOT_CONFIG_141", TITAN_PARAM_TYPE_F32, 20.5f, 220.5f, 120.5f, &s_param_val_141, FALSE },
    { 142, "MOT_CONFIG_142", TITAN_PARAM_TYPE_F32, 21.0f, 221.0f, 121.0f, &s_param_val_142, FALSE },
    { 143, "MOT_CONFIG_143", TITAN_PARAM_TYPE_F32, 21.5f, 221.5f, 121.5f, &s_param_val_143, FALSE },
    { 144, "MOT_CONFIG_144", TITAN_PARAM_TYPE_F32, 22.0f, 222.0f, 122.0f, &s_param_val_144, FALSE },
    { 145, "MOT_CONFIG_145", TITAN_PARAM_TYPE_F32, 22.5f, 222.5f, 122.5f, &s_param_val_145, FALSE },
    { 146, "MOT_CONFIG_146", TITAN_PARAM_TYPE_F32, 23.0f, 223.0f, 123.0f, &s_param_val_146, FALSE },
    { 147, "MOT_CONFIG_147", TITAN_PARAM_TYPE_F32, 23.5f, 223.5f, 123.5f, &s_param_val_147, FALSE },
    { 148, "MOT_CONFIG_148", TITAN_PARAM_TYPE_F32, 24.0f, 224.0f, 124.0f, &s_param_val_148, FALSE },
    { 149, "MOT_CONFIG_149", TITAN_PARAM_TYPE_F32, 24.5f, 224.5f, 124.5f, &s_param_val_149, FALSE },
    { 150, "MOT_CONFIG_150", TITAN_PARAM_TYPE_F32, 25.0f, 225.0f, 125.0f, &s_param_val_150, FALSE },
    { 151, "MOT_CONFIG_151", TITAN_PARAM_TYPE_F32, 25.5f, 225.5f, 125.5f, &s_param_val_151, FALSE },
    { 152, "MOT_CONFIG_152", TITAN_PARAM_TYPE_F32, 26.0f, 226.0f, 126.0f, &s_param_val_152, FALSE },
    { 153, "MOT_CONFIG_153", TITAN_PARAM_TYPE_F32, 26.5f, 226.5f, 126.5f, &s_param_val_153, FALSE },
    { 154, "MOT_CONFIG_154", TITAN_PARAM_TYPE_F32, 27.0f, 227.0f, 127.0f, &s_param_val_154, FALSE },
    { 155, "MOT_CONFIG_155", TITAN_PARAM_TYPE_F32, 27.5f, 227.5f, 127.5f, &s_param_val_155, FALSE },
    { 156, "MOT_CONFIG_156", TITAN_PARAM_TYPE_F32, 28.0f, 228.0f, 128.0f, &s_param_val_156, FALSE },
    { 157, "MOT_CONFIG_157", TITAN_PARAM_TYPE_F32, 28.5f, 228.5f, 128.5f, &s_param_val_157, FALSE },
    { 158, "MOT_CONFIG_158", TITAN_PARAM_TYPE_F32, 29.0f, 229.0f, 129.0f, &s_param_val_158, FALSE },
    { 159, "MOT_CONFIG_159", TITAN_PARAM_TYPE_F32, 29.5f, 229.5f, 129.5f, &s_param_val_159, FALSE },
    { 160, "MOT_CONFIG_160", TITAN_PARAM_TYPE_F32, 30.0f, 230.0f, 130.0f, &s_param_val_160, FALSE },
    { 161, "MOT_CONFIG_161", TITAN_PARAM_TYPE_F32, 30.5f, 230.5f, 130.5f, &s_param_val_161, FALSE },
    { 162, "MOT_CONFIG_162", TITAN_PARAM_TYPE_F32, 31.0f, 231.0f, 131.0f, &s_param_val_162, FALSE },
    { 163, "MOT_CONFIG_163", TITAN_PARAM_TYPE_F32, 31.5f, 231.5f, 131.5f, &s_param_val_163, FALSE },
    { 164, "MOT_CONFIG_164", TITAN_PARAM_TYPE_F32, 32.0f, 232.0f, 132.0f, &s_param_val_164, FALSE },
    { 165, "MOT_CONFIG_165", TITAN_PARAM_TYPE_F32, 32.5f, 232.5f, 132.5f, &s_param_val_165, FALSE },
    { 166, "MOT_CONFIG_166", TITAN_PARAM_TYPE_F32, 33.0f, 233.0f, 133.0f, &s_param_val_166, FALSE },
    { 167, "MOT_CONFIG_167", TITAN_PARAM_TYPE_F32, 33.5f, 233.5f, 133.5f, &s_param_val_167, FALSE },
    { 168, "MOT_CONFIG_168", TITAN_PARAM_TYPE_F32, 34.0f, 234.0f, 134.0f, &s_param_val_168, FALSE },
    { 169, "MOT_CONFIG_169", TITAN_PARAM_TYPE_F32, 34.5f, 234.5f, 134.5f, &s_param_val_169, FALSE },
    { 170, "MOT_CONFIG_170", TITAN_PARAM_TYPE_F32, 35.0f, 235.0f, 135.0f, &s_param_val_170, FALSE },
    { 171, "MOT_CONFIG_171", TITAN_PARAM_TYPE_F32, 35.5f, 235.5f, 135.5f, &s_param_val_171, FALSE },
    { 172, "MOT_CONFIG_172", TITAN_PARAM_TYPE_F32, 36.0f, 236.0f, 136.0f, &s_param_val_172, FALSE },
    { 173, "MOT_CONFIG_173", TITAN_PARAM_TYPE_F32, 36.5f, 236.5f, 136.5f, &s_param_val_173, FALSE },
    { 174, "MOT_CONFIG_174", TITAN_PARAM_TYPE_F32, 37.0f, 237.0f, 137.0f, &s_param_val_174, FALSE },
    { 175, "CAN_CONFIG_175", TITAN_PARAM_TYPE_F32, 37.5f, 237.5f, 137.5f, &s_param_val_175, FALSE },
    { 176, "CAN_CONFIG_176", TITAN_PARAM_TYPE_F32, 38.0f, 238.0f, 138.0f, &s_param_val_176, FALSE },
    { 177, "CAN_CONFIG_177", TITAN_PARAM_TYPE_F32, 38.5f, 238.5f, 138.5f, &s_param_val_177, FALSE },
    { 178, "CAN_CONFIG_178", TITAN_PARAM_TYPE_F32, 39.0f, 239.0f, 139.0f, &s_param_val_178, FALSE },
    { 179, "CAN_CONFIG_179", TITAN_PARAM_TYPE_F32, 39.5f, 239.5f, 139.5f, &s_param_val_179, FALSE },
    { 180, "CAN_CONFIG_180", TITAN_PARAM_TYPE_F32, 40.0f, 240.0f, 140.0f, &s_param_val_180, FALSE },
    { 181, "CAN_CONFIG_181", TITAN_PARAM_TYPE_F32, 40.5f, 240.5f, 140.5f, &s_param_val_181, FALSE },
    { 182, "CAN_CONFIG_182", TITAN_PARAM_TYPE_F32, 41.0f, 241.0f, 141.0f, &s_param_val_182, FALSE },
    { 183, "CAN_CONFIG_183", TITAN_PARAM_TYPE_F32, 41.5f, 241.5f, 141.5f, &s_param_val_183, FALSE },
    { 184, "CAN_CONFIG_184", TITAN_PARAM_TYPE_F32, 42.0f, 242.0f, 142.0f, &s_param_val_184, FALSE },
    { 185, "CAN_CONFIG_185", TITAN_PARAM_TYPE_F32, 42.5f, 242.5f, 142.5f, &s_param_val_185, FALSE },
    { 186, "CAN_CONFIG_186", TITAN_PARAM_TYPE_F32, 43.0f, 243.0f, 143.0f, &s_param_val_186, FALSE },
    { 187, "CAN_CONFIG_187", TITAN_PARAM_TYPE_F32, 43.5f, 243.5f, 143.5f, &s_param_val_187, FALSE },
    { 188, "CAN_CONFIG_188", TITAN_PARAM_TYPE_F32, 44.0f, 244.0f, 144.0f, &s_param_val_188, FALSE },
    { 189, "CAN_CONFIG_189", TITAN_PARAM_TYPE_F32, 44.5f, 244.5f, 144.5f, &s_param_val_189, FALSE },
    { 190, "CAN_CONFIG_190", TITAN_PARAM_TYPE_F32, 45.0f, 245.0f, 145.0f, &s_param_val_190, FALSE },
    { 191, "CAN_CONFIG_191", TITAN_PARAM_TYPE_F32, 45.5f, 245.5f, 145.5f, &s_param_val_191, FALSE },
    { 192, "CAN_CONFIG_192", TITAN_PARAM_TYPE_F32, 46.0f, 246.0f, 146.0f, &s_param_val_192, FALSE },
    { 193, "CAN_CONFIG_193", TITAN_PARAM_TYPE_F32, 46.5f, 246.5f, 146.5f, &s_param_val_193, FALSE },
    { 194, "CAN_CONFIG_194", TITAN_PARAM_TYPE_F32, 47.0f, 247.0f, 147.0f, &s_param_val_194, FALSE },
    { 195, "CAN_CONFIG_195", TITAN_PARAM_TYPE_F32, 47.5f, 247.5f, 147.5f, &s_param_val_195, FALSE },
    { 196, "CAN_CONFIG_196", TITAN_PARAM_TYPE_F32, 48.0f, 248.0f, 148.0f, &s_param_val_196, FALSE },
    { 197, "CAN_CONFIG_197", TITAN_PARAM_TYPE_F32, 48.5f, 248.5f, 148.5f, &s_param_val_197, FALSE },
    { 198, "CAN_CONFIG_198", TITAN_PARAM_TYPE_F32, 49.0f, 249.0f, 149.0f, &s_param_val_198, FALSE },
    { 199, "CAN_CONFIG_199", TITAN_PARAM_TYPE_F32, 49.5f, 249.5f, 149.5f, &s_param_val_199, FALSE },
    { 200, "CAN_CONFIG_200", TITAN_PARAM_TYPE_F32, 50.0f, 250.0f, 150.0f, &s_param_val_200, FALSE },
    { 201, "CAN_CONFIG_201", TITAN_PARAM_TYPE_F32, 50.5f, 250.5f, 150.5f, &s_param_val_201, FALSE },
    { 202, "CAN_CONFIG_202", TITAN_PARAM_TYPE_F32, 51.0f, 251.0f, 151.0f, &s_param_val_202, FALSE },
    { 203, "CAN_CONFIG_203", TITAN_PARAM_TYPE_F32, 51.5f, 251.5f, 151.5f, &s_param_val_203, FALSE },
    { 204, "CAN_CONFIG_204", TITAN_PARAM_TYPE_F32, 52.0f, 252.0f, 152.0f, &s_param_val_204, FALSE },
    { 205, "CAN_CONFIG_205", TITAN_PARAM_TYPE_F32, 52.5f, 252.5f, 152.5f, &s_param_val_205, FALSE },
    { 206, "CAN_CONFIG_206", TITAN_PARAM_TYPE_F32, 53.0f, 253.0f, 153.0f, &s_param_val_206, FALSE },
    { 207, "CAN_CONFIG_207", TITAN_PARAM_TYPE_F32, 53.5f, 253.5f, 153.5f, &s_param_val_207, FALSE },
    { 208, "CAN_CONFIG_208", TITAN_PARAM_TYPE_F32, 54.0f, 254.0f, 154.0f, &s_param_val_208, FALSE },
    { 209, "CAN_CONFIG_209", TITAN_PARAM_TYPE_F32, 54.5f, 254.5f, 154.5f, &s_param_val_209, FALSE },
    { 210, "MOD_CONFIG_210", TITAN_PARAM_TYPE_F32, 55.0f, 255.0f, 155.0f, &s_param_val_210, FALSE },
    { 211, "MOD_CONFIG_211", TITAN_PARAM_TYPE_F32, 55.5f, 255.5f, 155.5f, &s_param_val_211, FALSE },
    { 212, "MOD_CONFIG_212", TITAN_PARAM_TYPE_F32, 56.0f, 256.0f, 156.0f, &s_param_val_212, FALSE },
    { 213, "MOD_CONFIG_213", TITAN_PARAM_TYPE_F32, 56.5f, 256.5f, 156.5f, &s_param_val_213, FALSE },
    { 214, "MOD_CONFIG_214", TITAN_PARAM_TYPE_F32, 57.0f, 257.0f, 157.0f, &s_param_val_214, FALSE },
    { 215, "MOD_CONFIG_215", TITAN_PARAM_TYPE_F32, 57.5f, 257.5f, 157.5f, &s_param_val_215, FALSE },
    { 216, "MOD_CONFIG_216", TITAN_PARAM_TYPE_F32, 58.0f, 258.0f, 158.0f, &s_param_val_216, FALSE },
    { 217, "MOD_CONFIG_217", TITAN_PARAM_TYPE_F32, 58.5f, 258.5f, 158.5f, &s_param_val_217, FALSE },
    { 218, "MOD_CONFIG_218", TITAN_PARAM_TYPE_F32, 59.0f, 259.0f, 159.0f, &s_param_val_218, FALSE },
    { 219, "MOD_CONFIG_219", TITAN_PARAM_TYPE_F32, 59.5f, 259.5f, 159.5f, &s_param_val_219, FALSE },
    { 220, "MOD_CONFIG_220", TITAN_PARAM_TYPE_F32, 60.0f, 260.0f, 160.0f, &s_param_val_220, FALSE },
    { 221, "MOD_CONFIG_221", TITAN_PARAM_TYPE_F32, 60.5f, 260.5f, 160.5f, &s_param_val_221, FALSE },
    { 222, "MOD_CONFIG_222", TITAN_PARAM_TYPE_F32, 61.0f, 261.0f, 161.0f, &s_param_val_222, FALSE },
    { 223, "MOD_CONFIG_223", TITAN_PARAM_TYPE_F32, 61.5f, 261.5f, 161.5f, &s_param_val_223, FALSE },
    { 224, "MOD_CONFIG_224", TITAN_PARAM_TYPE_F32, 62.0f, 262.0f, 162.0f, &s_param_val_224, FALSE },
    { 225, "MOD_CONFIG_225", TITAN_PARAM_TYPE_F32, 62.5f, 262.5f, 162.5f, &s_param_val_225, FALSE },
    { 226, "MOD_CONFIG_226", TITAN_PARAM_TYPE_F32, 63.0f, 263.0f, 163.0f, &s_param_val_226, FALSE },
    { 227, "MOD_CONFIG_227", TITAN_PARAM_TYPE_F32, 63.5f, 263.5f, 163.5f, &s_param_val_227, FALSE },
    { 228, "MOD_CONFIG_228", TITAN_PARAM_TYPE_F32, 64.0f, 264.0f, 164.0f, &s_param_val_228, FALSE },
    { 229, "MOD_CONFIG_229", TITAN_PARAM_TYPE_F32, 64.5f, 264.5f, 164.5f, &s_param_val_229, FALSE },
    { 230, "MOD_CONFIG_230", TITAN_PARAM_TYPE_F32, 65.0f, 265.0f, 165.0f, &s_param_val_230, FALSE },
    { 231, "MOD_CONFIG_231", TITAN_PARAM_TYPE_F32, 65.5f, 265.5f, 165.5f, &s_param_val_231, FALSE },
    { 232, "MOD_CONFIG_232", TITAN_PARAM_TYPE_F32, 66.0f, 266.0f, 166.0f, &s_param_val_232, FALSE },
    { 233, "MOD_CONFIG_233", TITAN_PARAM_TYPE_F32, 66.5f, 266.5f, 166.5f, &s_param_val_233, FALSE },
    { 234, "MOD_CONFIG_234", TITAN_PARAM_TYPE_F32, 67.0f, 267.0f, 167.0f, &s_param_val_234, FALSE },
    { 235, "MOD_CONFIG_235", TITAN_PARAM_TYPE_F32, 67.5f, 267.5f, 167.5f, &s_param_val_235, FALSE },
    { 236, "MOD_CONFIG_236", TITAN_PARAM_TYPE_F32, 68.0f, 268.0f, 168.0f, &s_param_val_236, FALSE },
    { 237, "MOD_CONFIG_237", TITAN_PARAM_TYPE_F32, 68.5f, 268.5f, 168.5f, &s_param_val_237, FALSE },
    { 238, "MOD_CONFIG_238", TITAN_PARAM_TYPE_F32, 69.0f, 269.0f, 169.0f, &s_param_val_238, FALSE },
    { 239, "MOD_CONFIG_239", TITAN_PARAM_TYPE_F32, 69.5f, 269.5f, 169.5f, &s_param_val_239, FALSE },
    { 240, "MOD_CONFIG_240", TITAN_PARAM_TYPE_F32, 70.0f, 270.0f, 170.0f, &s_param_val_240, FALSE },
    { 241, "MOD_CONFIG_241", TITAN_PARAM_TYPE_F32, 70.5f, 270.5f, 170.5f, &s_param_val_241, FALSE },
    { 242, "MOD_CONFIG_242", TITAN_PARAM_TYPE_F32, 71.0f, 271.0f, 171.0f, &s_param_val_242, FALSE },
    { 243, "MOD_CONFIG_243", TITAN_PARAM_TYPE_F32, 71.5f, 271.5f, 171.5f, &s_param_val_243, FALSE },
    { 244, "MOD_CONFIG_244", TITAN_PARAM_TYPE_F32, 72.0f, 272.0f, 172.0f, &s_param_val_244, FALSE },
    { 245, "UDS_CONFIG_245", TITAN_PARAM_TYPE_F32, 72.5f, 272.5f, 172.5f, &s_param_val_245, FALSE },
    { 246, "UDS_CONFIG_246", TITAN_PARAM_TYPE_F32, 73.0f, 273.0f, 173.0f, &s_param_val_246, FALSE },
    { 247, "UDS_CONFIG_247", TITAN_PARAM_TYPE_F32, 73.5f, 273.5f, 173.5f, &s_param_val_247, FALSE },
    { 248, "UDS_CONFIG_248", TITAN_PARAM_TYPE_F32, 74.0f, 274.0f, 174.0f, &s_param_val_248, FALSE },
    { 249, "UDS_CONFIG_249", TITAN_PARAM_TYPE_F32, 74.5f, 274.5f, 174.5f, &s_param_val_249, FALSE },
    { 250, "UDS_CONFIG_250", TITAN_PARAM_TYPE_F32, 75.0f, 275.0f, 175.0f, &s_param_val_250, FALSE },
    { 251, "UDS_CONFIG_251", TITAN_PARAM_TYPE_F32, 75.5f, 275.5f, 175.5f, &s_param_val_251, FALSE },
    { 252, "UDS_CONFIG_252", TITAN_PARAM_TYPE_F32, 76.0f, 276.0f, 176.0f, &s_param_val_252, FALSE },
    { 253, "UDS_CONFIG_253", TITAN_PARAM_TYPE_F32, 76.5f, 276.5f, 176.5f, &s_param_val_253, FALSE },
    { 254, "UDS_CONFIG_254", TITAN_PARAM_TYPE_F32, 77.0f, 277.0f, 177.0f, &s_param_val_254, FALSE },
    { 255, "UDS_CONFIG_255", TITAN_PARAM_TYPE_F32, 77.5f, 277.5f, 177.5f, &s_param_val_255, FALSE },
    { 256, "UDS_CONFIG_256", TITAN_PARAM_TYPE_F32, 78.0f, 278.0f, 178.0f, &s_param_val_256, FALSE },
    { 257, "UDS_CONFIG_257", TITAN_PARAM_TYPE_F32, 78.5f, 278.5f, 178.5f, &s_param_val_257, FALSE },
    { 258, "UDS_CONFIG_258", TITAN_PARAM_TYPE_F32, 79.0f, 279.0f, 179.0f, &s_param_val_258, FALSE },
    { 259, "UDS_CONFIG_259", TITAN_PARAM_TYPE_F32, 79.5f, 279.5f, 179.5f, &s_param_val_259, FALSE },
    { 260, "UDS_CONFIG_260", TITAN_PARAM_TYPE_F32, 80.0f, 280.0f, 180.0f, &s_param_val_260, FALSE },
    { 261, "UDS_CONFIG_261", TITAN_PARAM_TYPE_F32, 80.5f, 280.5f, 180.5f, &s_param_val_261, FALSE },
    { 262, "UDS_CONFIG_262", TITAN_PARAM_TYPE_F32, 81.0f, 281.0f, 181.0f, &s_param_val_262, FALSE },
    { 263, "UDS_CONFIG_263", TITAN_PARAM_TYPE_F32, 81.5f, 281.5f, 181.5f, &s_param_val_263, FALSE },
    { 264, "UDS_CONFIG_264", TITAN_PARAM_TYPE_F32, 82.0f, 282.0f, 182.0f, &s_param_val_264, FALSE },
    { 265, "UDS_CONFIG_265", TITAN_PARAM_TYPE_F32, 82.5f, 282.5f, 182.5f, &s_param_val_265, FALSE },
    { 266, "UDS_CONFIG_266", TITAN_PARAM_TYPE_F32, 83.0f, 283.0f, 183.0f, &s_param_val_266, FALSE },
    { 267, "UDS_CONFIG_267", TITAN_PARAM_TYPE_F32, 83.5f, 283.5f, 183.5f, &s_param_val_267, FALSE },
    { 268, "UDS_CONFIG_268", TITAN_PARAM_TYPE_F32, 84.0f, 284.0f, 184.0f, &s_param_val_268, FALSE },
    { 269, "UDS_CONFIG_269", TITAN_PARAM_TYPE_F32, 84.5f, 284.5f, 184.5f, &s_param_val_269, FALSE },
    { 270, "UDS_CONFIG_270", TITAN_PARAM_TYPE_F32, 85.0f, 285.0f, 185.0f, &s_param_val_270, FALSE },
    { 271, "UDS_CONFIG_271", TITAN_PARAM_TYPE_F32, 85.5f, 285.5f, 185.5f, &s_param_val_271, FALSE },
    { 272, "UDS_CONFIG_272", TITAN_PARAM_TYPE_F32, 86.0f, 286.0f, 186.0f, &s_param_val_272, FALSE },
    { 273, "UDS_CONFIG_273", TITAN_PARAM_TYPE_F32, 86.5f, 286.5f, 186.5f, &s_param_val_273, FALSE },
    { 274, "UDS_CONFIG_274", TITAN_PARAM_TYPE_F32, 87.0f, 287.0f, 187.0f, &s_param_val_274, FALSE },
    { 275, "UDS_CONFIG_275", TITAN_PARAM_TYPE_F32, 87.5f, 287.5f, 187.5f, &s_param_val_275, FALSE },
    { 276, "UDS_CONFIG_276", TITAN_PARAM_TYPE_F32, 88.0f, 288.0f, 188.0f, &s_param_val_276, FALSE },
    { 277, "UDS_CONFIG_277", TITAN_PARAM_TYPE_F32, 88.5f, 288.5f, 188.5f, &s_param_val_277, FALSE },
    { 278, "UDS_CONFIG_278", TITAN_PARAM_TYPE_F32, 89.0f, 289.0f, 189.0f, &s_param_val_278, FALSE },
    { 279, "UDS_CONFIG_279", TITAN_PARAM_TYPE_F32, 89.5f, 289.5f, 189.5f, &s_param_val_279, FALSE },
    { 280, "SAF_CONFIG_280", TITAN_PARAM_TYPE_F32, 90.0f, 290.0f, 190.0f, &s_param_val_280, FALSE },
    { 281, "SAF_CONFIG_281", TITAN_PARAM_TYPE_F32, 90.5f, 290.5f, 190.5f, &s_param_val_281, FALSE },
    { 282, "SAF_CONFIG_282", TITAN_PARAM_TYPE_F32, 91.0f, 291.0f, 191.0f, &s_param_val_282, FALSE },
    { 283, "SAF_CONFIG_283", TITAN_PARAM_TYPE_F32, 91.5f, 291.5f, 191.5f, &s_param_val_283, FALSE },
    { 284, "SAF_CONFIG_284", TITAN_PARAM_TYPE_F32, 92.0f, 292.0f, 192.0f, &s_param_val_284, FALSE },
    { 285, "SAF_CONFIG_285", TITAN_PARAM_TYPE_F32, 92.5f, 292.5f, 192.5f, &s_param_val_285, FALSE },
    { 286, "SAF_CONFIG_286", TITAN_PARAM_TYPE_F32, 93.0f, 293.0f, 193.0f, &s_param_val_286, FALSE },
    { 287, "SAF_CONFIG_287", TITAN_PARAM_TYPE_F32, 93.5f, 293.5f, 193.5f, &s_param_val_287, FALSE },
    { 288, "SAF_CONFIG_288", TITAN_PARAM_TYPE_F32, 94.0f, 294.0f, 194.0f, &s_param_val_288, FALSE },
    { 289, "SAF_CONFIG_289", TITAN_PARAM_TYPE_F32, 94.5f, 294.5f, 194.5f, &s_param_val_289, FALSE },
    { 290, "SAF_CONFIG_290", TITAN_PARAM_TYPE_F32, 95.0f, 295.0f, 195.0f, &s_param_val_290, FALSE },
    { 291, "SAF_CONFIG_291", TITAN_PARAM_TYPE_F32, 95.5f, 295.5f, 195.5f, &s_param_val_291, FALSE },
    { 292, "SAF_CONFIG_292", TITAN_PARAM_TYPE_F32, 96.0f, 296.0f, 196.0f, &s_param_val_292, FALSE },
    { 293, "SAF_CONFIG_293", TITAN_PARAM_TYPE_F32, 96.5f, 296.5f, 196.5f, &s_param_val_293, FALSE },
    { 294, "SAF_CONFIG_294", TITAN_PARAM_TYPE_F32, 97.0f, 297.0f, 197.0f, &s_param_val_294, FALSE },
    { 295, "SAF_CONFIG_295", TITAN_PARAM_TYPE_F32, 97.5f, 297.5f, 197.5f, &s_param_val_295, FALSE },
    { 296, "SAF_CONFIG_296", TITAN_PARAM_TYPE_F32, 98.0f, 298.0f, 198.0f, &s_param_val_296, FALSE },
    { 297, "SAF_CONFIG_297", TITAN_PARAM_TYPE_F32, 98.5f, 298.5f, 198.5f, &s_param_val_297, FALSE },
    { 298, "SAF_CONFIG_298", TITAN_PARAM_TYPE_F32, 99.0f, 299.0f, 199.0f, &s_param_val_298, FALSE },
    { 299, "SAF_CONFIG_299", TITAN_PARAM_TYPE_F32, 99.5f, 299.5f, 199.5f, &s_param_val_299, FALSE },
    { 300, "SAF_CONFIG_300", TITAN_PARAM_TYPE_F32, 100.0f, 300.0f, 200.0f, &s_param_val_300, FALSE },
    { 301, "SAF_CONFIG_301", TITAN_PARAM_TYPE_F32, 100.5f, 300.5f, 200.5f, &s_param_val_301, FALSE },
    { 302, "SAF_CONFIG_302", TITAN_PARAM_TYPE_F32, 101.0f, 301.0f, 201.0f, &s_param_val_302, FALSE },
    { 303, "SAF_CONFIG_303", TITAN_PARAM_TYPE_F32, 101.5f, 301.5f, 201.5f, &s_param_val_303, FALSE },
    { 304, "SAF_CONFIG_304", TITAN_PARAM_TYPE_F32, 102.0f, 302.0f, 202.0f, &s_param_val_304, FALSE },
    { 305, "SAF_CONFIG_305", TITAN_PARAM_TYPE_F32, 102.5f, 302.5f, 202.5f, &s_param_val_305, FALSE },
    { 306, "SAF_CONFIG_306", TITAN_PARAM_TYPE_F32, 103.0f, 303.0f, 203.0f, &s_param_val_306, FALSE },
    { 307, "SAF_CONFIG_307", TITAN_PARAM_TYPE_F32, 103.5f, 303.5f, 203.5f, &s_param_val_307, FALSE },
    { 308, "SAF_CONFIG_308", TITAN_PARAM_TYPE_F32, 104.0f, 304.0f, 204.0f, &s_param_val_308, FALSE },
    { 309, "SAF_CONFIG_309", TITAN_PARAM_TYPE_F32, 104.5f, 304.5f, 204.5f, &s_param_val_309, FALSE },
    { 310, "SAF_CONFIG_310", TITAN_PARAM_TYPE_F32, 105.0f, 305.0f, 205.0f, &s_param_val_310, FALSE },
    { 311, "SAF_CONFIG_311", TITAN_PARAM_TYPE_F32, 105.5f, 305.5f, 205.5f, &s_param_val_311, FALSE },
    { 312, "SAF_CONFIG_312", TITAN_PARAM_TYPE_F32, 106.0f, 306.0f, 206.0f, &s_param_val_312, FALSE },
    { 313, "SAF_CONFIG_313", TITAN_PARAM_TYPE_F32, 106.5f, 306.5f, 206.5f, &s_param_val_313, FALSE },
    { 314, "SAF_CONFIG_314", TITAN_PARAM_TYPE_F32, 107.0f, 307.0f, 207.0f, &s_param_val_314, FALSE },
    { 315, "SYS_CONFIG_315", TITAN_PARAM_TYPE_F32, 107.5f, 307.5f, 207.5f, &s_param_val_315, FALSE },
    { 316, "SYS_CONFIG_316", TITAN_PARAM_TYPE_F32, 108.0f, 308.0f, 208.0f, &s_param_val_316, FALSE },
    { 317, "SYS_CONFIG_317", TITAN_PARAM_TYPE_F32, 108.5f, 308.5f, 208.5f, &s_param_val_317, FALSE },
    { 318, "SYS_CONFIG_318", TITAN_PARAM_TYPE_F32, 109.0f, 309.0f, 209.0f, &s_param_val_318, FALSE },
    { 319, "SYS_CONFIG_319", TITAN_PARAM_TYPE_F32, 109.5f, 309.5f, 209.5f, &s_param_val_319, FALSE },
    { 320, "SYS_CONFIG_320", TITAN_PARAM_TYPE_F32, 110.0f, 310.0f, 210.0f, &s_param_val_320, FALSE },
    { 321, "SYS_CONFIG_321", TITAN_PARAM_TYPE_F32, 110.5f, 310.5f, 210.5f, &s_param_val_321, FALSE },
    { 322, "SYS_CONFIG_322", TITAN_PARAM_TYPE_F32, 111.0f, 311.0f, 211.0f, &s_param_val_322, FALSE },
    { 323, "SYS_CONFIG_323", TITAN_PARAM_TYPE_F32, 111.5f, 311.5f, 211.5f, &s_param_val_323, FALSE },
    { 324, "SYS_CONFIG_324", TITAN_PARAM_TYPE_F32, 112.0f, 312.0f, 212.0f, &s_param_val_324, FALSE },
    { 325, "SYS_CONFIG_325", TITAN_PARAM_TYPE_F32, 112.5f, 312.5f, 212.5f, &s_param_val_325, FALSE },
    { 326, "SYS_CONFIG_326", TITAN_PARAM_TYPE_F32, 113.0f, 313.0f, 213.0f, &s_param_val_326, FALSE },
    { 327, "SYS_CONFIG_327", TITAN_PARAM_TYPE_F32, 113.5f, 313.5f, 213.5f, &s_param_val_327, FALSE },
    { 328, "SYS_CONFIG_328", TITAN_PARAM_TYPE_F32, 114.0f, 314.0f, 214.0f, &s_param_val_328, FALSE },
    { 329, "SYS_CONFIG_329", TITAN_PARAM_TYPE_F32, 114.5f, 314.5f, 214.5f, &s_param_val_329, FALSE },
    { 330, "SYS_CONFIG_330", TITAN_PARAM_TYPE_F32, 115.0f, 315.0f, 215.0f, &s_param_val_330, FALSE },
    { 331, "SYS_CONFIG_331", TITAN_PARAM_TYPE_F32, 115.5f, 315.5f, 215.5f, &s_param_val_331, FALSE },
    { 332, "SYS_CONFIG_332", TITAN_PARAM_TYPE_F32, 116.0f, 316.0f, 216.0f, &s_param_val_332, FALSE },
    { 333, "SYS_CONFIG_333", TITAN_PARAM_TYPE_F32, 116.5f, 316.5f, 216.5f, &s_param_val_333, FALSE },
    { 334, "SYS_CONFIG_334", TITAN_PARAM_TYPE_F32, 117.0f, 317.0f, 217.0f, &s_param_val_334, FALSE },
    { 335, "SYS_CONFIG_335", TITAN_PARAM_TYPE_F32, 117.5f, 317.5f, 217.5f, &s_param_val_335, FALSE },
    { 336, "SYS_CONFIG_336", TITAN_PARAM_TYPE_F32, 118.0f, 318.0f, 218.0f, &s_param_val_336, FALSE },
    { 337, "SYS_CONFIG_337", TITAN_PARAM_TYPE_F32, 118.5f, 318.5f, 218.5f, &s_param_val_337, FALSE },
    { 338, "SYS_CONFIG_338", TITAN_PARAM_TYPE_F32, 119.0f, 319.0f, 219.0f, &s_param_val_338, FALSE },
    { 339, "SYS_CONFIG_339", TITAN_PARAM_TYPE_F32, 119.5f, 319.5f, 219.5f, &s_param_val_339, FALSE },
    { 340, "SYS_CONFIG_340", TITAN_PARAM_TYPE_F32, 120.0f, 320.0f, 220.0f, &s_param_val_340, FALSE },
    { 341, "SYS_CONFIG_341", TITAN_PARAM_TYPE_F32, 120.5f, 320.5f, 220.5f, &s_param_val_341, FALSE },
    { 342, "SYS_CONFIG_342", TITAN_PARAM_TYPE_F32, 121.0f, 321.0f, 221.0f, &s_param_val_342, FALSE },
    { 343, "SYS_CONFIG_343", TITAN_PARAM_TYPE_F32, 121.5f, 321.5f, 221.5f, &s_param_val_343, FALSE },
    { 344, "SYS_CONFIG_344", TITAN_PARAM_TYPE_F32, 122.0f, 322.0f, 222.0f, &s_param_val_344, FALSE },
    { 345, "SYS_CONFIG_345", TITAN_PARAM_TYPE_F32, 122.5f, 322.5f, 222.5f, &s_param_val_345, FALSE },
    { 346, "SYS_CONFIG_346", TITAN_PARAM_TYPE_F32, 123.0f, 323.0f, 223.0f, &s_param_val_346, FALSE },
    { 347, "SYS_CONFIG_347", TITAN_PARAM_TYPE_F32, 123.5f, 323.5f, 223.5f, &s_param_val_347, FALSE },
    { 348, "SYS_CONFIG_348", TITAN_PARAM_TYPE_F32, 124.0f, 324.0f, 224.0f, &s_param_val_348, FALSE },
    { 349, "SYS_CONFIG_349", TITAN_PARAM_TYPE_F32, 124.5f, 324.5f, 224.5f, &s_param_val_349, FALSE },
};

titan_status_t titan_param_init_all(void)
{
    for (u16_t i = 0; i < TITAN_PARAM_COUNT; ++i) {
        s_param_table[i].val_ptr = &s_param_val_0 + i;
        *(f32_t*)s_param_table[i].val_ptr = s_param_table[i].default_val;
        s_param_table[i].is_dirty = FALSE;
    }
    return TITAN_OK;
}

titan_status_t titan_param_get_by_id(u16_t id, f32_t *out_val)
{
    if (id >= TITAN_PARAM_COUNT || !out_val) return TITAN_ERROR_INVALID_ARGUMENT;
    *out_val = *(f32_t*)s_param_table[id].val_ptr;
    return TITAN_OK;
}

titan_status_t titan_param_set_by_id(u16_t id, f32_t in_val)
{
    if (id >= TITAN_PARAM_COUNT) return TITAN_ERROR_INVALID_ARGUMENT;
    if (in_val < s_param_table[id].min_val || in_val > s_param_table[id].max_val) {
        return TITAN_ERROR_OUT_OF_BOUNDS;
    }
    *(f32_t*)s_param_table[id].val_ptr = in_val;
    s_param_table[id].is_dirty = TRUE;
    return TITAN_OK;
}

titan_status_t titan_param_reset_defaults(void)
{
    return titan_param_init_all();
}

const titan_param_entry_t* titan_param_find_by_name(const char *name)
{
    if (!name) return NULL_PTR;
    for (u16_t i = 0; i < TITAN_PARAM_COUNT; ++i) {
        if (titan_strcmp(s_param_table[i].name, name) == 0) {
            return &s_param_table[i];
        }
    }
    return NULL_PTR;
}
