/* FUN_8007b514
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007b514  body 0x8007b514..0x8007b9ff  size 1260 B
 * body sha256 23b5221d446c1273d0eec78393d59f428d9ca0d4df82dd8eabf34ecb81d397a6
 * provider record sha256 24e0ed34a4daa1ab110f24c303b0bc2817e708b48c3c9f82202fdb299df7b7b3
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007b514(int param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined2 local_20;
  short local_1e;
  short local_1c;
  
  uVar5 = *(undefined4 *)(param_1 + 0x22c);
  uVar6 = *(undefined4 *)(param_1 + 0x230);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
    *(undefined1 *)(param_1 + 6) = 1;
    if ((DAT_800e9012 & 8) != 0) {
      *(uint *)(*(int *)(param_1 + 0x234) + 0x1608) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x1608) | 1;
      *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x234) + 0x120) + 0xc) = 0x200;
      FUN_80066288(param_1);
      iVar4 = *(int *)(param_1 + 0x234);
      *(undefined2 *)(*(int *)(iVar4 + 0x1728) + 0xc) = 0x200;
      FUN_80066288(param_1,iVar4 + 0x1608);
    }
    local_20 = 200;
    local_1e = 0xfe70;
    local_1c = 0xff38;
    iVar4 = *(int *)(param_1 + 0x234) + 0x38;
    FUN_80037780(6000,(int)*(short *)(param_1 + 0x66),iVar4,&local_20);
    local_20 = 0x96;
    local_1e = -0x15e;
    local_1c = -200;
    FUN_80037780(6000,(int)((*(ushort *)(param_1 + 0x66) + 0x800) * 0x10000) >> 0x10,iVar4,&local_20
                );
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x206) = 5;
    *(undefined1 *)(param_1 + 0x207) = 0;
  case 1:
    if (*(byte *)(param_1 + 0x1e9) < 0x2a) {
      if ((*(byte *)(param_1 + 0x1e9) & 3) == 0) {
        local_20 = 200;
        local_1e = *(short *)(param_1 + 500) * 0x1e + -400;
        iVar4 = *(int *)(param_1 + 0x234) + 0x38;
        local_1c = *(short *)(param_1 + 500) * 0xf + -200;
        FUN_80037780(0x10bb8,(int)*(short *)(param_1 + 0x66),iVar4,&local_20);
        local_20 = 100;
        local_1e = *(short *)(param_1 + 500) * 0x19 + -0x15e;
        local_1c = *(short *)(param_1 + 500) * 0xf + -200;
        FUN_80037780(5000,(int)((*(ushort *)(param_1 + 0x66) + 0x800) * 0x10000) >> 0x10,iVar4,
                     &local_20);
        *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
      }
      if (*(byte *)(param_1 + 0x1e9) < 0x2a) {
        if ((DAT_800e9012 & 8) != 0) {
          if (*(char *)(param_1 + 0x206) < '\x04') {
            iVar3 = *(int *)(param_1 + 0x234);
            iVar4 = *(int *)(iVar3 + 0x120);
            *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) + -0x50;
            FUN_80066288(param_1,iVar3);
            iVar4 = *(int *)(param_1 + 0x234);
            iVar3 = *(int *)(iVar4 + 0x1728);
            sVar1 = *(short *)(iVar3 + 0xc) + -0x50;
          }
          else {
            iVar3 = *(int *)(param_1 + 0x234);
            iVar4 = *(int *)(iVar3 + 0x120);
            *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) + 200;
            FUN_80066288(param_1,iVar3);
            iVar4 = *(int *)(param_1 + 0x234);
            iVar3 = *(int *)(iVar4 + 0x1728);
            sVar1 = *(short *)(iVar3 + 0xc) + 200;
          }
          *(short *)(iVar3 + 0xc) = sVar1;
          FUN_80066288(param_1,iVar4 + 0x1608);
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
        FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
        FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
      }
      cVar2 = *(char *)(param_1 + 0x1e9);
    }
    if ((cVar2 == '2') && ((DAT_800e9012 & 0xc) != 0)) {
      FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
      FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
    }
    if (((0x32 < *(byte *)(param_1 + 0x1e9)) && (*(char *)(param_1 + 0x207) == '\0')) &&
       ((DAT_800e9012 & 8) != 0)) {
      iVar4 = *(int *)(param_1 + 0x234);
      *(short *)(*(int *)(iVar4 + 0x120) + 0xc) = *(short *)(*(int *)(iVar4 + 0x120) + 0xc) + 200;
      if (0x1000 < *(short *)(*(int *)(iVar4 + 0x120) + 0xc)) {
        *(undefined2 *)(*(int *)(iVar4 + 0x120) + 0xc) = 0x1000;
        *(undefined1 *)(param_1 + 0x207) = 1;
      }
      FUN_80066288(param_1,iVar4);
      iVar4 = *(int *)(param_1 + 0x234);
      *(short *)(*(int *)(iVar4 + 0x1728) + 0xc) = *(short *)(*(int *)(iVar4 + 0x1728) + 0xc) + 200;
      if (0x1000 < *(short *)(*(int *)(iVar4 + 0x1728) + 0xc)) {
        *(undefined2 *)(*(int *)(iVar4 + 0x1728) + 0xc) = 0x1000;
      }
      FUN_80066288(param_1,iVar4 + 0x1608);
    }
    if ((*(byte *)(param_1 + 0x1e9) - 0x24 < 0x13) && ((*(byte *)(param_1 + 0x1e9) & 3) == 0)) {
      FUN_80037780(0x21770,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x38,0);
    }
    if (*(char *)(param_1 + 0x1e9) == 'F') {
      *(undefined1 *)(DAT_800e13f4 + 6) = 5;
    }
    cVar2 = FUN_80089d54(param_1,uVar5,uVar6,0x100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    break;
  case 2:
    *(undefined2 *)(param_1 + 500) = 0x96;
    *(undefined1 *)(param_1 + 6) = 3;
  }
  return;
}
