/* FUN_80162b60
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80162b60  body 0x80162b60..0x80162d4b  size 492 B
 * body sha256 4c908d31836541b8e8686016ca7149819fc4904b9c8d2ac36bf23c9082bcdb40
 * provider record sha256 745351ad76f5e8ad5be3fa40472568274a07e2555fbb3c107a5bdad8ef5df546
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162b60(uint *param_1)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  
  iVar1 = _DAT_800e1364;
  iVar4 = (uint)*(byte *)((int)param_1 + 0x2c2) * 0xe;
  if (*(char *)((int)param_1 + 6) == '\0') {
    func_0x80077d18(3,param_1);
    *param_1 = *param_1 | 0x3000000;
    *(undefined2 *)(param_1 + 0x19) = *(undefined2 *)(&DAT_80163944 + iVar4);
    *(undefined2 *)((int)param_1 + 0x66) = *(undefined2 *)(&DAT_80163946 + iVar4);
    *(undefined2 *)(param_1 + 0x1a) = *(undefined2 *)(&DAT_80163948 + iVar4);
    param_1[0x1c] = iVar1 + (uint)*(ushort *)(&DAT_8016393c + iVar4) * 0x178 + 0x38;
    uVar2 = func_0x80033604();
    *(short *)(param_1 + 0x7d) = (short)((uVar2 & 0xff) >> 4) + 0x5a;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  else if (*(char *)((int)param_1 + 6) != '\x01') goto LAB_80162d18;
  param_1[10] = (int)*(short *)(&DAT_8016393e + iVar4);
  param_1[0xb] = (int)*(short *)(&DAT_80163940 + iVar4);
  param_1[0xc] = (int)*(short *)(&DAT_80163942 + iVar4);
  func_0x80036b84(param_1,2,0,0);
  if ((_DAT_800df90e == 0) && (_DAT_8010c274 == 0)) {
    sVar3 = *(short *)(param_1 + 0x7d) + -1;
  }
  else {
    sVar3 = *(short *)(param_1 + 0x7d) + -8;
  }
  *(short *)(param_1 + 0x7d) = sVar3;
  if ((*(short *)(param_1 + 0x7d) < 0) && (DAT_80163b08 == 0)) {
    param_1[1] = 0x1040000;
    DAT_80163b04 = DAT_80163b04 - 1;
    if (DAT_80163b04 == 0) {
      DAT_800e1134 = 1;
      DAT_800e1135 = 0;
      _DAT_800e1136 = 0;
    }
  }
LAB_80162d18:
  if (2 < DAT_80163b04) {
    DAT_80163b0c = DAT_80163b0c + 1;
  }
  return;
}
