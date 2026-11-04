/* FUN_80166788
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80166788  body 0x80166788..0x80166c1b  size 1172 B
 * body sha256 81e046c3ceb0e84b76d1a54fec66f8a634df003a264612ab473adc26e495152f
 * provider record sha256 72fedc85cf6c11ae2d2bea8c99297490b4917965fe78275479522bc921b744d5
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166788(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined2 uVar2;
  code *pcVar3;
  byte bVar6;
  ushort uVar5;
  uint uVar4;
  char cVar7;
  int iVar8;
  undefined2 local_20;
  short local_1e;
  undefined2 local_1c;
  
  if ((DAT_800e1134 == '\x05') && (_DAT_800e1380 == param_1)) {
    DAT_800e139f = DAT_800e139f & 0x7f;
    DAT_800e138c = DAT_800e138c & 0xed;
    *param_1 = *param_1 & 0xffffeffb;
    _DAT_800e1134 = 0x1000000;
    _DAT_800e1130 = _DAT_800e1130 & 0xffffeffb;
  }
  if ((*(ushort *)((int)param_1 + 0x1aa) & 1) == 0) {
    if ((*(ushort *)((int)param_1 + 0x2b6) & 0x10) != 0) {
      FUN_8016922c(param_1,param_2,param_3);
      return;
    }
    iVar8 = 0;
    if (((*(ushort *)((int)param_1 + 0x1aa) & 0x40) != 0) && (*(char *)((int)param_1 + 5) != '\x01')
       ) {
      iVar8 = 0x17;
    }
    if ((*(char *)((int)param_1 + 6) == '\0') && (*(char *)((int)param_1 + 0x2bf) <= iVar8)) {
      if ((*(char *)((int)param_1 + 0x2be) == '\x01') || (*(char *)((int)param_1 + 5) == '\x01')) {
        *(undefined1 *)((int)param_1 + 0x2be) = 1;
        param_1[1] = 0x1050000;
        bVar6 = func_0x80033604(iVar8,param_2);
        *(byte *)((int)param_1 + 0x2bf) = (bVar6 & 0xf) + 0x10;
        if ((uint)*(byte *)((int)param_1 + 0x26e) % 3 == 0) {
          local_20 = 0;
          local_1e = 800;
          local_1c = 0;
          func_0x80037780(0x17d0,(int)*(short *)((int)param_1 + 0x66),param_1[0x8d] + 0x1b0,
                          &local_20);
          return;
        }
        uVar4 = param_1[0x8d];
        local_20 = *(undefined2 *)(uVar4 + 0xbde);
        local_1e = *(short *)(uVar4 + 0xbe2) + 500;
        local_1c = *(undefined2 *)(uVar4 + 0xbe6);
        func_0x80037780(0x1000,(int)*(short *)((int)param_1 + 0x66),param_1[0x8d] + 0x38,&local_20);
        return;
      }
      *(undefined1 *)((int)param_1 + 0x2be) = 1;
    }
    if ((*(ushort *)((int)param_1 + 0x2b6) & 2) != 0) {
      param_1[1] = 0x1050600;
      *(undefined1 *)((int)param_1 + 0x207) = 1;
      if ((*(char *)((int)param_1 + 5) == '\n') && ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) == 0)
         ) {
        FUN_80167910(param_1);
        *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x800;
      }
      cVar7 = *(char *)((int)param_1 + 5);
      if (cVar7 == '\v') {
        FUN_80167abc(param_1);
        cVar7 = *(char *)((int)param_1 + 5);
      }
      if ((cVar7 == '\t') && ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) == 0)) {
        FUN_80167ba4(param_1);
      }
      cVar7 = *(char *)((int)param_1 + 5);
      if (cVar7 == '\x0e') {
        FUN_80167c88(param_1);
        cVar7 = *(char *)((int)param_1 + 5);
      }
      if (cVar7 != '\x10') {
        return;
      }
      if (((*(ushort *)((int)param_1 + 0x1aa) & 0x80) == 0) && (8 < *(byte *)((int)param_1 + 0x2d6))
         ) {
        FUN_80167910(param_1);
        *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x800;
      }
      *(char *)((int)param_1 + 0x2d6) = *(char *)((int)param_1 + 0x2d6) + '\x01';
      return;
    }
    if ((((*(ushort *)((int)param_1 + 0x2b6) & 0x60) == 0) &&
        (*(char *)((int)param_1 + 0x1ee) < '\0')) && ((param_1[0x9b] & 0xc00000) != 0)) {
      func_0x80077d18(9,param_1);
      if ((param_1[0x9b] & 0x800000) == 0) {
        iVar8 = param_1[0x8d] + 0xd38;
        uVar5 = *(ushort *)((int)param_1 + 0x2b6) | 0x20;
      }
      else {
        iVar8 = param_1[0x8d] + 0x11a0;
        uVar5 = *(ushort *)((int)param_1 + 0x2b6) | 0x40;
      }
      *(ushort *)((int)param_1 + 0x2b6) = uVar5;
      uVar4 = func_0x80033604();
      if (((uVar4 & 1) != 0) && (*(char *)(param_1 + 2) != '\x1e')) {
        uVar4 = param_1[0x8d];
        *(undefined4 *)(iVar8 + 0xb4) = *(undefined4 *)(uVar4 + 0x16bc);
        *(undefined4 *)(iVar8 + 0xbc) = *(undefined4 *)(uVar4 + 0x16c4);
        *(undefined4 *)(iVar8 + 0xb8) = *(undefined4 *)(uVar4 + 0x16c0);
        *(undefined4 *)(iVar8 + 0xc0) = *(undefined4 *)(uVar4 + 0x16c8);
      }
      uVar4 = func_0x80033604();
      func_0x80037780(8000,(uVar4 & 0xff) << 4,iVar8 + 0x38,0);
      uVar4 = *(uint *)(iVar8 + 0x178);
      if ((DAT_800e9012 & 8) != 0) {
        uVar4 = uVar4 | 0x1062;
      }
      *(uint *)(iVar8 + 0x178) = uVar4;
      sVar1 = *(short *)((int)param_1 + 0x66);
      *(undefined2 *)(iVar8 + 0x1a4) = 10;
      *(undefined2 *)(iVar8 + 0x1a2) = 0xff38;
      *(undefined2 *)(iVar8 + 0x296) = 0;
      *(undefined1 *)(iVar8 + 0x289) = 0x32;
      *(undefined2 *)(iVar8 + 0x1a6) = 0;
      *(short *)(iVar8 + 0x1a0) = sVar1 + 0x800;
      uVar2 = *(undefined2 *)((int)param_1 + 0x66);
      *(undefined2 *)(iVar8 + 0x1aa) = 0x400;
      *(undefined2 *)(iVar8 + 0x1a8) = uVar2;
      uVar4 = func_0x80033604();
      func_0x80037780(7000,(uVar4 & 0xff) << 4,iVar8 + 0x1b0,0);
    }
    pcVar3 = (code *)(&PTR_FUN_8016e284)
                     [(*(byte *)((int)param_1 + 5) - 1) * 9 + (uint)*(byte *)((int)param_1 + 0x26e)]
    ;
  }
  else {
    pcVar3 = (code *)(&PTR_FUN_8016e50c)[*(byte *)((int)param_1 + 5) - 1];
  }
  (*pcVar3)(param_1,param_2,param_3);
  return;
}
