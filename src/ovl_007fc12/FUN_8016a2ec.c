/* FUN_8016a2ec
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016a2ec  body 0x8016a2ec..0x8016aa8f  size 1956 B
 * body sha256 2e0935368842e3f6185d21f27dc8c108cf40a4f073c68edcaaa0deae7a5cd4d7
 * provider record sha256 83241e0aa603e87b7b56be07b96e2f2ebf1a7dd43b5cfe392de9ce71903c7eff
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016a2ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  char cVar7;
  ushort uVar5;
  short sVar6;
  uint *puVar8;
  int iVar9;
  undefined2 local_38 [4];
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  byte local_28 [8];
  
  local_38[0] = 0xfe3e;
  local_38[1] = 0xfa;
  local_28[0] = 2;
  local_28[1] = 1;
  if (*(char *)(param_1 + 0x2cd) == '\x01') {
    FUN_8016ae0c();
    return;
  }
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    uVar4 = func_0x80033604();
    if (((uVar4 & 3) == 0) || (_DAT_800e1130 < 0)) {
LAB_8016a3c4:
      if ((*(char *)(param_1 + 5) == '\t') || (*(char *)(param_1 + 5) == '\x11')) {
LAB_8016a3dc:
        if ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0) {
          FUN_80167ba4(param_1);
        }
      }
      uVar4 = func_0x80033604();
      uVar3 = func_0x80033604();
      if ((((int)(uVar4 & 0xff) >> (uVar3 & 7) & 3U) == 0) || (*(char *)(param_1 + 5) != '\t')) {
        *(char *)(param_1 + 0x207) = (char)((*(ushort *)(param_1 + 0x26c) & 0x20) >> 5);
        uVar5 = *(ushort *)(param_1 + 0x2b6) & 0xfffb;
        *(ushort *)(param_1 + 0x2b6) = uVar5;
        if (*(char *)(param_1 + 0x207) == '\0') {
          *(ushort *)(param_1 + 0x2b6) = uVar5 | 4;
        }
        *(undefined1 *)(param_1 + 6) = 1;
        *(undefined2 *)(param_1 + 0x1f6) = 10;
        *(int *)(param_1 + 0x1e8) = (4 - *(char *)(param_1 + 0x207)) * 0x1000000 + 0x300;
        uVar2 = local_38[*(char *)(param_1 + 0x207)];
        *(undefined2 *)(param_1 + 0x1e4) = 0;
        *(undefined2 *)(param_1 + 0x1e0) = uVar2;
        func_0x80032b5c(param_1,0);
        *(undefined1 *)(param_1 + 0x25c) = 1;
        iVar9 = *(int *)(param_1 + 0x234);
        *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
        uVar4 = *(uint *)(iVar9 + 0xbc0);
        if ((DAT_800e9012 & 8) != 0) {
          uVar4 = uVar4 | 0x4a;
        }
        *(uint *)(iVar9 + 0xbc0) = uVar4;
        sVar6 = *(short *)(param_1 + 0x66);
        *(undefined2 *)(iVar9 + 0xcf4) = 400;
        *(undefined2 *)(iVar9 + 0xcf2) = 0xff9c;
        *(undefined2 *)(iVar9 + 0xcf8) = 0;
        *(undefined2 *)(iVar9 + 0xcf6) = 10;
        *(undefined2 *)(iVar9 + 0xcfc) = 0xffce;
        *(undefined4 *)(iVar9 + 0xc20) = 0x101030;
        *(short *)(iVar9 + 0xcf0) = sVar6 + 0x800;
        uVar4 = func_0x80033604();
        func_0x80037780(3000,(uVar4 & 0xff) << 4,iVar9 + 0xbf8,0);
        func_0x80038e98(5,3,iVar9 + 0xbf8);
        iVar9 = *(int *)(param_1 + 0x234);
        if ((*(ushort *)(param_1 + 0x2b6) & 0x20) == 0) {
          uVar4 = *(uint *)(iVar9 + 0xd38);
          if ((DAT_800e9012 & 8) != 0) {
            uVar4 = uVar4 | 0x1062;
          }
          *(uint *)(iVar9 + 0xd38) = uVar4;
          sVar6 = *(short *)(param_1 + 0x66);
          *(undefined2 *)(iVar9 + 0xd64) = 100;
          *(undefined2 *)(iVar9 + 0xe56) = 0;
          *(undefined2 *)(iVar9 + 0xd62) = 0;
          *(undefined1 *)(iVar9 + 0xe49) = 0x1e;
          *(undefined2 *)(iVar9 + 0xd66) = 0;
          *(short *)(iVar9 + 0xd60) = sVar6 + 0x800;
          uVar2 = *(undefined2 *)(param_1 + 0x66);
          *(undefined2 *)(iVar9 + 0xd6a) = 0x400;
          *(undefined2 *)(iVar9 + 0xd68) = uVar2;
          iVar9 = *(int *)(param_1 + 0x234);
          *(uint *)(iVar9 + 0xeb0) = *(uint *)(iVar9 + 0xeb0) | 0x80;
          *(undefined4 *)(iVar9 + 0xfe0) = 0x40;
          *(undefined4 *)(iVar9 + 0xfe4) = 0x101010;
        }
        else {
          *(undefined4 *)(iVar9 + 0xd38) = 0;
          *(undefined4 *)(iVar9 + 0xeb0) = 0;
          func_0x80038e98(5,3,iVar9 + 0xee8);
          *(undefined4 *)(iVar9 + 0x1028) = 0;
          func_0x80038e98(5,3,iVar9 + 0x1060);
        }
        iVar9 = *(int *)(param_1 + 0x234);
        if (((*(ushort *)(param_1 + 0x2b6) & 0x40) == 0) &&
           (uVar4 = func_0x80033604(), (uVar4 & 1) == 0)) {
          uVar4 = *(uint *)(iVar9 + 0x11a0);
          if ((DAT_800e9012 & 8) != 0) {
            uVar4 = uVar4 | 0x1062;
          }
          *(uint *)(iVar9 + 0x11a0) = uVar4;
          sVar6 = *(short *)(param_1 + 0x66);
          *(undefined2 *)(iVar9 + 0x11cc) = 100;
          *(undefined2 *)(iVar9 + 0x12be) = 0;
          *(undefined2 *)(iVar9 + 0x11ca) = 0;
          *(undefined1 *)(iVar9 + 0x12b1) = 0x1e;
          *(undefined2 *)(iVar9 + 0x11ce) = 0;
          *(short *)(iVar9 + 0x11c8) = sVar6 + 0x800;
          uVar2 = *(undefined2 *)(param_1 + 0x66);
          *(undefined2 *)(iVar9 + 0x11d2) = 0x400;
          *(undefined2 *)(iVar9 + 0x11d0) = uVar2;
          *(uint *)(iVar9 + 0x1318) = *(uint *)(iVar9 + 0x1318) | 0x80;
          *(undefined4 *)(iVar9 + 0x1448) = 0x40;
          *(undefined4 *)(iVar9 + 0x144c) = 0x101010;
        }
        iVar9 = *(int *)(param_1 + 0x234);
        *(uint *)(iVar9 + 0x1028) = *(uint *)(iVar9 + 0x1028) | 0x80;
        *(undefined4 *)(iVar9 + 0x1158) = 0x40;
        *(undefined4 *)(iVar9 + 0x115c) = 0x101010;
        puVar8 = *(uint **)(param_1 + 0x234);
        puVar8[0x4c] = 0x20;
        puVar8[0x4d] = 0x20;
        *puVar8 = *puVar8 | 0x80;
        if ((DAT_800e9012 & 8) != 0) {
          iVar9 = *(int *)(param_1 + 0x234);
          *(undefined4 *)(iVar9 + 0xa8) = *(undefined4 *)(iVar9 + 0x1828);
          *(undefined4 *)(iVar9 + 0xac) = *(undefined4 *)(iVar9 + 0x182c);
          *(undefined4 *)(iVar9 + 0xb0) = *(undefined4 *)(iVar9 + 0x1830);
          *(undefined4 *)(iVar9 + 0xb4) = *(undefined4 *)(iVar9 + 0x1834);
          *(undefined2 *)(iVar9 + 0xc4) = *(undefined2 *)(iVar9 + 0x1844);
          *(undefined2 *)(iVar9 + 0xc6) = *(undefined2 *)(iVar9 + 0x1846);
          *(undefined4 *)(iVar9 + 0xcc) = *(undefined4 *)(iVar9 + 0x184c);
          *(undefined4 *)(iVar9 + 200) = *(undefined4 *)(iVar9 + 0x1848);
        }
        iVar9 = *(int *)(param_1 + 0x234);
        local_30 = 0;
        local_2e = 0xfe0c;
        local_2c = 0;
        uVar4 = func_0x80033604();
        uVar3 = func_0x80033604();
        iVar9 = iVar9 + 0x38;
        func_0x80037780(8000,(int)(((uint)*(ushort *)(param_1 + 0x66) + (uVar4 & 0xff) * 0x10 +
                                   (uVar3 & 0xff) * -0x10) * 0x10000) >> 0x10,iVar9,&local_30);
        uVar4 = func_0x80033604();
        uVar3 = func_0x80033604();
        func_0x80037780(((uVar4 & 0xff) + 4000) * 4 | 0x8000000,(uVar3 & 0xff) << 4,iVar9,&local_30)
        ;
        func_0x80077d18(2,param_1);
        func_0x80035b84(param_1);
        *(undefined2 *)(param_1 + 0x1e0) = 0xb;
        goto switchD_8016a378_caseD_1;
      }
    }
    else {
      if (*(char *)(param_1 + 5) == '\t') goto LAB_8016a3dc;
      if (*(char *)(param_1 + 5) == '\x11') goto LAB_8016a3c4;
    }
    *(undefined1 *)(param_1 + 0x2cd) = 1;
    FUN_8016ae0c(param_1,param_2,param_3);
    break;
  case 1:
switchD_8016a378_caseD_1:
    func_0x800334c8(param_1,param_2,param_3,0);
    cVar7 = func_0x80089d54(param_1,param_2,param_3,0x400);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar7;
    func_0x80032b5c(param_1,0);
    if (*(short *)(param_1 + 0x1f6) != 0) {
      if ((*(ushort *)(param_1 + 0x1f6) & 1) == 0) {
        iVar9 = *(int *)(param_1 + 0x234);
        uVar4 = func_0x80033604();
        uVar3 = func_0x80033604();
        iVar9 = iVar9 + 0x38;
        func_0x80037780(8000,(int)(((uint)*(ushort *)(param_1 + 0x66) + (uVar4 & 0xff) * 0x10 +
                                   (uVar3 & 0xff) * -0x10) * 0x10000) >> 0x10,iVar9,param_1 + 0x1e0)
        ;
        uVar4 = func_0x80033604();
        uVar3 = func_0x80033604();
        func_0x80037780(8000,(int)(((uint)*(ushort *)(param_1 + 0x66) + (uVar4 & 0xff) * 0x10 +
                                   (uVar3 & 0xff) * -0x10) * 0x10000) >> 0x10,iVar9,param_1 + 0x1e0)
        ;
      }
      *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -1;
    }
    break;
  case 2:
    uVar4 = func_0x80033604();
    if ((uVar4 & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 5;
      return;
    }
    bVar1 = local_28[*(char *)(param_1 + 0x207)];
    *(undefined1 *)(param_1 + 6) = 3;
    *(uint *)(param_1 + 0x1e8) =
         (uint)bVar1 * 0x1000000 + (*(char *)(param_1 + 0x207) * 0xf + 10) * 0x10000 + 0x700;
  case 3:
    cVar7 = func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar7;
    if (*(char *)(param_1 + 0x1ea) == '\0') {
      func_0x80033680(param_1,0,1);
    }
    break;
  case 4:
    *(undefined4 *)(param_1 + 4) = 0x7000000;
    break;
  case 5:
    *(undefined1 *)(param_1 + 6) = 6;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x1000000 + 0xf00;
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar5 & 0x1f) + 0xf;
  case 6:
    sVar6 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar6;
    if (sVar6 == -1) {
      *(undefined1 *)(param_1 + 6) = 3;
      *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfffb;
    }
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),8);
    func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
    func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100)
    ;
    func_0x80032b5c(param_1,0);
  }
  return;
}
