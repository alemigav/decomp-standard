/* FUN_80165c68
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80165c68  body 0x80165c68..0x80165ea7  size 576 B
 * body sha256 b4c64e9da3de37f5c41769c1080cc60ea17ef37e59b2cc6212d588739b33caef
 * provider record sha256 5e538929d0575c78aaff9cc214cb6e0b638484a00d380cc5ac039e7dfd76d86b
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165c68(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar3;
  short sVar2;
  byte bVar4;
  undefined4 uVar5;
  
  bVar4 = *(byte *)((int)param_1 + 6);
  if (bVar4 != 1) {
    if (1 < bVar4) {
      if (bVar4 == 2) {
        param_1[1] = 0x1050200;
        bVar4 = func_0x80033604();
        *(byte *)((int)param_1 + 0x2bf) = (bVar4 & 0xf) + 0x10;
        *(undefined1 *)((int)param_1 + 0x206) = 0;
        return;
      }
      return;
    }
    if (bVar4 != 0) {
      return;
    }
    param_1[0x7a] = 0xa000f00;
    *(undefined1 *)((int)param_1 + 6) = 1;
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x98),(int)*(short *)((int)param_1 + 0x262),
                    0x80);
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined1 *)((int)param_1 + 0x2be) = 0;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xfffb | 2;
    *param_1 = *param_1 & 0xf3ffffff | 0x4000000;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x2000;
    if (*(char *)((int)param_1 + 0x2d5) == '\0') {
      uVar1 = func_0x80033604();
      uVar5 = 0xb;
      if ((uVar1 & 1) != 0) {
        uVar5 = 10;
      }
      func_0x80077d18(uVar5,param_1);
      *(undefined1 *)((int)param_1 + 0x2d5) = 0x96;
    }
  }
  sVar2 = *(short *)(param_1 + 0x7d);
  *(ushort *)(param_1 + 0x7d) = sVar2 + 1U;
  if ((sVar2 + 1U & 1) == 0) {
    *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) >> 2;
  }
  else {
    func_0x800334c8(param_1,param_2,param_3,0);
  }
  cVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar3;
  func_0x80032b5c(param_1,0);
  if (*(byte *)((int)param_1 + 0x1e9) < 0x12) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x98),(int)*(short *)((int)param_1 + 0x262),
                    0x10);
  }
  else {
    sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x100);
    if ((((sVar2 == 0) && (param_1[0xa3] < 0x708)) && ((DAT_800e139f & 0x80) == 0)) &&
       (*(char *)((int)param_1 + 0x1a2) == DAT_800e12d2)) {
      param_1[1] = 0x1010000;
      *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xffc0 | 1;
      DAT_800e139f = DAT_800e139f | 0x80;
    }
  }
  return;
}
