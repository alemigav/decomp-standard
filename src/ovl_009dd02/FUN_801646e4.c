/* FUN_801646e4
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801646e4  body 0x801646e4..0x8016485b  size 376 B
 * body sha256 f164238d665e3fc82f4434c8a0e4e2e2655f47817152171f68c1de1f54befd8b
 * provider record sha256 17aeb570e42c97d478abc1f2200b8f00cf054119a493d2bb276a2ac91a61b5ba
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801646e4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  short sVar3;
  int iVar2;
  
  if (*(char *)(param_1 + 7) == '\0') {
    uVar1 = *(undefined1 *)(param_1 + 0x2b8);
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined1 *)(param_1 + 0x2b6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x1e;
    *(undefined2 *)(param_1 + 0x1f6) = 0x2d;
    *(undefined1 *)(param_1 + 0x2dc) = 0x83;
    *(undefined1 *)(param_1 + 0x2c1) = 5;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
    *(undefined1 *)(param_1 + 0x2b8) = 0;
    *(undefined1 *)(param_1 + 0x2bf) = 0x5a;
    *(uint *)(param_1 + 0x1e8) = ((uint)*(byte *)(param_1 + 0x2cd) * 0xd + 8) * 0x1000000 + 0x3f00;
    *(undefined1 *)(param_1 + 0x2c0) = uVar1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
    _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
    _DAT_800e1134 = 0x5000000;
    _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
    DAT_800e139f = DAT_800e139f | 0x80;
    _DAT_800e1130 = _DAT_800e1130 | 0x42;
    _DAT_800e1380 = param_1;
    func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
    func_0x80077d18(0xd,param_1);
  }
  sVar3 = func_0x80032e74(&DAT_800e1130,*(undefined4 *)(param_1 + 0x28),
                          *(undefined4 *)(param_1 + 0x30),0x100);
  if (sVar3 != 0) {
    _DAT_800e1196 = _DAT_800e1196 + sVar3;
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar2 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
    _DAT_800e1196 = *(short *)(param_1 + 0x66) + (*(byte *)(param_1 + 0x2cd) ^ 1) * 0x800;
  }
  return;
}
