/* FUN_8007adb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007adb4  body 0x8007adb4..0x8007ae03  size 80 B
 * body sha256 92557ee305afba9b87a0f200256f15cf53268c59641b4f8187b4df0333da9d83
 * provider record sha256 0e3920e83d760494ac14edcc9686bb1f5c5c0f58b9638591cdb84a36ab4af6e8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007adb4(int param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined2 uStack_20;
  short sStack_1e;
  short sStack_1c;
  
  uVar5 = *(undefined4 *)(param_1 + 0x22c);
  uVar6 = *(undefined4 *)(param_1 + 0x230);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
    *(undefined1 *)(param_1 + 6) = 1;
    if ((DAT_800e9012 & 8) != 0) {
      *(uint *)(*(int *)(param_1 + 0x234) + 0x1780) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x1780) | 1;
      *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x234) + 0x120) + 0x10) = 0x200;
      FUN_80066288(param_1);
      iVar3 = *(int *)(param_1 + 0x234);
      *(undefined2 *)(*(int *)(iVar3 + 0x18a0) + 0x10) = 0x200;
      FUN_80066288(param_1,iVar3 + 0x1780);
    }
    uStack_20 = 200;
    sStack_1e = 0xfe70;
    sStack_1c = 0xff38;
    iVar3 = *(int *)(param_1 + 0x234) + 0x38;
    FUN_80037780(6000,(int)*(short *)(param_1 + 0x66),iVar3,&uStack_20);
    uStack_20 = 0x96;
    sStack_1e = -0x15e;
    sStack_1c = -200;
    FUN_80037780(6000,(int)((*(ushort *)(param_1 + 0x66) + 0x800) * 0x10000) >> 0x10,iVar3,
                 &uStack_20);
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x206) = 5;
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) | 0x8000;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xeb0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xeb0) | 0x8000;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x1028) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x1028) | 0x8000;
  case 1:
    if (*(byte *)(param_1 + 0x1e9) < 0x2a) {
      if ((*(byte *)(param_1 + 0x1e9) & 3) == 0) {
        uStack_20 = 200;
        sStack_1e = *(short *)(param_1 + 500) * 0x1e + -400;
        iVar3 = *(int *)(param_1 + 0x234) + 0x38;
        sStack_1c = *(short *)(param_1 + 500) * 0xf + -200;
        FUN_80037780(0x10bb8,(int)*(short *)(param_1 + 0x66),iVar3,&uStack_20);
        uStack_20 = 100;
        sStack_1e = *(short *)(param_1 + 500) * 0x19 + -0x15e;
        sStack_1c = *(short *)(param_1 + 500) * 0xf + -200;
        FUN_80037780(5000,(int)((*(ushort *)(param_1 + 0x66) + 0x800) * 0x10000) >> 0x10,iVar3,
                     &uStack_20);
        *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
      }
      if (*(byte *)(param_1 + 0x1e9) < 0x2a) {
        if ((DAT_800e9012 & 8) != 0) {
          if (*(char *)(param_1 + 0x206) < '\x04') {
            iVar4 = *(int *)(param_1 + 0x234);
            iVar3 = *(int *)(iVar4 + 0x120);
            *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + -0x50;
            FUN_80066288(param_1,iVar4);
            iVar3 = *(int *)(param_1 + 0x234);
            iVar4 = *(int *)(iVar3 + 0x18a0);
            sVar1 = *(short *)(iVar4 + 0x10) + -0x50;
          }
          else {
            iVar4 = *(int *)(param_1 + 0x234);
            iVar3 = *(int *)(iVar4 + 0x120);
            *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + 200;
            FUN_80066288(param_1,iVar4);
            iVar3 = *(int *)(param_1 + 0x234);
            iVar4 = *(int *)(iVar3 + 0x18a0);
            sVar1 = *(short *)(iVar4 + 0x10) + 200;
          }
          *(short *)(iVar4 + 0x10) = sVar1;
          FUN_80066288(param_1,iVar3 + 0x1780);
        }
        cVar2 = *(char *)(param_1 + 0x206) + -1;
        *(char *)(param_1 + 0x206) = cVar2;
        if (cVar2 == -1) {
          *(undefined1 *)(param_1 + 0x206) = 5;
        }
      }
    }
    cVar2 = *(char *)(param_1 + 0x1e9);
    if (cVar2 == '(') {
      if ((DAT_800e9012 & 0xc) != 0) {
        FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
      }
      cVar2 = *(char *)(param_1 + 0x1e9);
    }
    if ((cVar2 == '2') && ((DAT_800e9012 & 0xc) != 0)) {
      FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
      FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
      FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xeb0,1);
      FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
      FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x1318,1);
    }
    if (((0x32 < *(byte *)(param_1 + 0x1e9)) && (*(char *)(param_1 + 0x207) == '\0')) &&
       ((DAT_800e9012 & 8) != 0)) {
      iVar3 = *(int *)(param_1 + 0x234);
      *(short *)(*(int *)(iVar3 + 0x120) + 0x10) = *(short *)(*(int *)(iVar3 + 0x120) + 0x10) + 200;
      if (0x1000 < *(short *)(*(int *)(iVar3 + 0x120) + 0x10)) {
        *(undefined2 *)(*(int *)(iVar3 + 0x120) + 0x10) = 0x1000;
        *(undefined1 *)(param_1 + 0x207) = 1;
      }
      FUN_80066288(param_1,iVar3);
      iVar3 = *(int *)(param_1 + 0x234);
      *(short *)(*(int *)(iVar3 + 0x18a0) + 0x10) =
           *(short *)(*(int *)(iVar3 + 0x18a0) + 0x10) + 200;
      if (0x1000 < *(short *)(*(int *)(iVar3 + 0x18a0) + 0x10)) {
        *(undefined2 *)(*(int *)(iVar3 + 0x18a0) + 0x10) = 0x1000;
      }
      FUN_80066288(param_1,iVar3 + 0x1780);
    }
    if ((*(byte *)(param_1 + 0x1e9) - 0x24 < 0x13) && ((*(byte *)(param_1 + 0x1e9) & 3) == 0)) {
      FUN_80037780(0x21770,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x38,0);
    }
    if (*(char *)(param_1 + 0x1e9) == 'F') {
      *(undefined1 *)(DAT_800e13f4 + 6) = 5;
    }
    cVar2 = FUN_80089d54(param_1,uVar5,uVar6,0x100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    switchD_8007adfc::caseD_4();
    return;
  case 2:
    *(undefined2 *)(param_1 + 500) = 0x96;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    if (*(short *)(param_1 + 500) == 0x82) {
      *(char *)(DAT_800e13f4 + 6) = *(char *)(DAT_800e13f4 + 6) + '\x01';
    }
    if ((DAT_800e9012 & 8) != 0) {
      if (*(ushort *)(param_1 + 500) - 0x78 < 10) {
        iVar4 = *(int *)(param_1 + 0x234);
        iVar3 = *(int *)(iVar4 + 0x120);
        *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + 100;
        FUN_80066288(param_1,iVar4);
        iVar3 = *(int *)(param_1 + 0x234);
        iVar4 = *(int *)(iVar3 + 0x18a0);
        *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + 100;
        FUN_80066288(param_1,iVar3 + 0x1780);
      }
      if (*(ushort *)(param_1 + 500) - 0x72 < 5) {
        iVar4 = *(int *)(param_1 + 0x234);
        iVar3 = *(int *)(iVar4 + 0x120);
        *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + -200;
        FUN_80066288(param_1,iVar4);
        iVar3 = *(int *)(param_1 + 0x234);
        iVar4 = *(int *)(iVar3 + 0x18a0);
        *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + -200;
        FUN_80066288(param_1,iVar3 + 0x1780);
      }
      if (*(ushort *)(param_1 + 500) - 0x67 < 10) {
        iVar4 = *(int *)(param_1 + 0x234);
        iVar3 = *(int *)(iVar4 + 0x120);
        *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + 0x50;
        FUN_80066288(param_1,iVar4);
        iVar3 = *(int *)(param_1 + 0x234);
        iVar4 = *(int *)(iVar3 + 0x18a0);
        *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + 0x50;
        FUN_80066288(param_1,iVar3 + 0x1780);
      }
      if (*(ushort *)(param_1 + 500) - 0x61 < 5) {
        iVar4 = *(int *)(param_1 + 0x234);
        iVar3 = *(int *)(iVar4 + 0x120);
        *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + -0xa0;
        FUN_80066288(param_1,iVar4);
        iVar3 = *(int *)(param_1 + 0x234);
        iVar4 = *(int *)(iVar3 + 0x18a0);
        *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + -0xa0;
        FUN_80066288(param_1,iVar3 + 0x1780);
      }
    }
    if ((*(ushort *)(param_1 + 500) - 0x74 < 0x18) && ((*(ushort *)(param_1 + 500) & 7) == 0)) {
      FUN_80037780(0x20fa0,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x38,0);
    }
    sVar1 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar1;
    if (sVar1 == -1) {
      *(undefined1 *)(param_1 + 6) = 4;
      *(char *)(DAT_800e13f4 + 6) = *(char *)(DAT_800e13f4 + 6) + '\x01';
    }
  default:
    return;
  }
}
