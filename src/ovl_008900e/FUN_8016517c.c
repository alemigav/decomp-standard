/* FUN_8016517c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x8016517c  body 0x8016517c..0x801654b3  size 824 B
 * body sha256 fe2de9d975e9e9da4cee1d1c0e90b8bccf2af6cbcf2582df1f69120c8e51063e
 * provider record sha256 e53cd64b640915787a2c21b5c35eb6bd327abaf9fc08fc8b210f8fe4df2ba73c
 * callees 7 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016517c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  short local_20 [2];
  short local_1c;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0x1000f00;
    *(undefined1 *)((int)param_1 + 0x2ce) = 4;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 2;
  case 1:
    uVar2 = FUN_801621c4(param_1,&DAT_80168bec);
    iVar1 = FUN_80162768(param_1);
    if ((iVar1 != 0) || ((uVar2 & 0x20000000) != 0)) {
      param_1[1] = 0x10d0000;
      return;
    }
    if ((int)uVar2 < 0) {
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x8008a994(param_1,param_2,param_3,0x100);
      func_0x80032c6c(param_1,0,0);
      return;
    }
    *param_1 = *param_1 | 4;
    if ((uVar2 & 0x40000000) == 0) {
      *(undefined1 *)((int)param_1 + 6) = 3;
      *(char *)(param_1 + 0xad) = (char)uVar2;
switchD_801651c0_caseD_3:
      param_1[0x7a] = 0x11000f00;
      *(undefined1 *)((int)param_1 + 6) = 4;
      goto switchD_801651c0_caseD_4;
    }
    *(undefined1 *)((int)param_1 + 6) = 5;
  case 5:
    param_1[0x7a] = 0x10000f00;
    *(undefined1 *)((int)param_1 + 6) = 6;
  case 6:
    iVar1 = func_0x8008a994(param_1,param_2,param_3,0x100);
    if (iVar1 == 0) {
      return;
    }
    local_20[0] = 0x670;
    local_1c = 0;
    iVar1 = ((uint)*(byte *)((int)param_1 + 0x206) - (uint)*(byte *)((int)param_1 + 0x207)) * 0x400;
    DAT_80168d5a = (ushort)iVar1;
    func_0x800837d0((int)((iVar1 + (uint)*(byte *)((int)param_1 + 0x206) * 0x400) * 0x10000) >> 0x10
                    ,local_20,local_20);
    uVar3 = (uint)*(byte *)((int)param_1 + 0x207) + ((int)((uint)DAT_80168d5a << 0x10) >> 0x1a);
    uVar2 = uVar3 & 3;
    *(char *)((int)param_1 + 0x207) = (char)uVar2;
    if ((uVar3 & 1) == 0) {
      param_1[0xc] = param_1[0xc] + (int)local_1c;
      uVar2 = func_0x8006a880(*(undefined1 *)((int)param_1 + 0x207),param_1[0xaf]);
      param_1[10] = uVar2;
    }
    else {
      param_1[10] = param_1[10] + (int)local_20[0];
      uVar2 = func_0x8006a880(uVar2,param_1[0xaf]);
      param_1[0xc] = uVar2;
    }
    uVar2 = *param_1;
    *(undefined1 *)((int)param_1 + 6) = 0;
    break;
  default:
    return;
  case 3:
    goto switchD_801651c0_caseD_3;
  case 4:
switchD_801651c0_caseD_4:
    iVar1 = func_0x8008a994(param_1,param_2,param_3,0x100);
    if (iVar1 == 0) {
      return;
    }
    local_20[0] = 0x69d;
    local_1c = 0;
    iVar1 = ((uint)*(byte *)((int)param_1 + 0x206) - (uint)*(byte *)((int)param_1 + 0x207)) * 0x400
            + ((uint)*(byte *)((int)param_1 + 0x206) - (uint)*(byte *)(param_1 + 0xad)) * 0x400;
    DAT_80168d5a = (ushort)iVar1;
    func_0x800837d0((int)((iVar1 + (uint)*(byte *)((int)param_1 + 0x206) * 0x400) * 0x10000) >> 0x10
                    ,local_20,local_20);
    if ((param_1[0xad] & 0x1000000) == 0) {
      param_1[0xc] = param_1[0xc] + (int)local_1c;
      uVar2 = func_0x8006a880(*(undefined1 *)(param_1 + 0xad),param_1[0xaf]);
      param_1[10] = uVar2;
    }
    else {
      param_1[10] = param_1[10] + (int)local_20[0];
      uVar2 = func_0x8006a880(*(undefined1 *)(param_1 + 0xad),param_1[0xaf]);
      param_1[0xc] = uVar2;
    }
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 0x100;
    uVar2 = *param_1;
    *(undefined1 *)((int)param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 0x207) = *(undefined1 *)(param_1 + 0xad);
  }
  *param_1 = uVar2 & 0xfffffffb;
  return;
}
