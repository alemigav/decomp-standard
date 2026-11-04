/* FUN_80162820
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80162820  body 0x80162820..0x80162a77  size 600 B
 * body sha256 bf4025947ed3416206d18882a5741c573ec250207461a3049bb1af20ac417347
 * provider record sha256 f95092342c5363a3ad0f1cf24b617e33d79fa6d0c958878f5db6c89051fa5b7f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162820(int param_1)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  byte bVar5;
  uint uVar6;
  
  bVar1 = false;
  uVar6 = *(uint *)(param_1 + 0x28c);
  sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x4c8);
  sVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x270);
  sVar4 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  if ((*(short *)(param_1 + 0x2c0) == 0) || (*(short *)(param_1 + 0x1f2) < 100)) {
    *(undefined2 *)(param_1 + 0x1aa) = 1;
    *(undefined4 *)(param_1 + 4) = 0x1060000;
  }
  else if ((sVar4 == 0) && (uVar6 < 0x5dc)) {
    *(undefined4 *)(param_1 + 4) = 0x1050000;
    *(undefined2 *)(param_1 + 500) = 0x28;
  }
  else {
    if ((((*(char *)(param_1 + 0x2b6) == '\0') && (DAT_800e139f == '\0')) && (sVar4 == 0)) &&
       ((uVar6 < 0xd48 && (0x9c4 < uVar6)))) {
      *(undefined4 *)(param_1 + 4) = 0x1020000;
      bVar1 = true;
    }
    if (((uVar6 < 0x9c4) && (sVar2 == 0)) &&
       ((DAT_800e139f == '\0' && (*(byte *)(param_1 + 0x2b6) < 10)))) {
      *(undefined4 *)(param_1 + 4) = 0x1040000;
      bVar1 = true;
    }
    if ((((*(char *)(param_1 + 0x2b6) != '\0') && (DAT_800e139f == '\0')) && (sVar3 == 0)) &&
       (((uVar6 < 0xd48 && ((_DAT_800e112a & 4) != 0)) &&
        (uVar6 = func_0x80033604(), (uVar6 & 3) == 0)))) {
      *(undefined4 *)(param_1 + 4) = 0x1080000;
      bVar1 = true;
    }
    if (((_DAT_800e1322 != 0) && (_DAT_800e1322 < 0x3c)) && (bVar1)) {
      bVar5 = *(char *)(param_1 + 0x2c4) + 1;
      *(byte *)(param_1 + 0x2c4) = bVar5;
      if (bVar5 < 3) {
        *(undefined4 *)(param_1 + 4) = 0x1030000;
      }
      else {
        *(undefined1 *)(param_1 + 0x2c4) = 0;
      }
    }
  }
  return;
}
