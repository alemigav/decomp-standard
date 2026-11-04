/* FUN_8007ae04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ae04  body 0x8007ae04..0x8007af1f  size 284 B
 * body sha256 c639fe439f6a4b1a810a0f3d9677da9854637498f0d6464f480d2728dd7e8e66
 * provider record sha256 630e56b20f275db4970a7f8a0ae3c43489d85f066068935c339e3c876d455385
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007adfc::caseD_0(void)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int unaff_s2;
  undefined4 uStack00000010;
  short sStack00000014;
  
  *(undefined4 *)(unaff_s2 + 0x1e8) = 0xf00;
  *(undefined1 *)(unaff_s2 + 6) = 1;
  if ((DAT_800e9012 & 8) != 0) {
    *(uint *)(*(int *)(unaff_s2 + 0x234) + 0x1780) =
         *(uint *)(*(int *)(unaff_s2 + 0x234) + 0x1780) | 1;
    *(undefined2 *)(*(int *)(*(int *)(unaff_s2 + 0x234) + 0x120) + 0x10) = 0x200;
    FUN_80066288();
    *(undefined2 *)(*(int *)(*(int *)(unaff_s2 + 0x234) + 0x18a0) + 0x10) = 0x200;
    FUN_80066288();
  }
  uStack00000010._0_2_ = 200;
  uStack00000010._2_2_ = 0xfe70;
  sStack00000014 = 0xff38;
  iVar4 = *(int *)(unaff_s2 + 0x234) + 0x38;
  FUN_80037780(6000,(int)*(short *)(unaff_s2 + 0x66),iVar4,&uStack00000010);
  uStack00000010._0_2_ = 0x96;
  uStack00000010._2_2_ = -0x15e;
  sStack00000014 = -200;
  FUN_80037780(6000,(int)((*(ushort *)(unaff_s2 + 0x66) + 0x800) * 0x10000) >> 0x10,iVar4,
               &uStack00000010);
  *(undefined2 *)(unaff_s2 + 500) = 0;
  *(undefined1 *)(unaff_s2 + 0x206) = 5;
  *(undefined1 *)(unaff_s2 + 0x207) = 0;
  *(uint *)(*(int *)(unaff_s2 + 0x234) + 0xd38) =
       *(uint *)(*(int *)(unaff_s2 + 0x234) + 0xd38) | 0x8000;
  *(uint *)(*(int *)(unaff_s2 + 0x234) + 0xeb0) =
       *(uint *)(*(int *)(unaff_s2 + 0x234) + 0xeb0) | 0x8000;
  *(uint *)(*(int *)(unaff_s2 + 0x234) + 0x1028) =
       *(uint *)(*(int *)(unaff_s2 + 0x234) + 0x1028) | 0x8000;
  if (*(byte *)(unaff_s2 + 0x1e9) < 0x2a) {
    if ((*(byte *)(unaff_s2 + 0x1e9) & 3) == 0) {
      uStack00000010._0_2_ = 200;
      uStack00000010._2_2_ = *(short *)(unaff_s2 + 500) * 0x1e + -400;
      iVar4 = *(int *)(unaff_s2 + 0x234) + 0x38;
      sStack00000014 = *(short *)(unaff_s2 + 500) * 0xf + -200;
      FUN_80037780(0x10bb8,(int)*(short *)(unaff_s2 + 0x66),iVar4,&uStack00000010);
      uStack00000010._0_2_ = 100;
      uStack00000010._2_2_ = *(short *)(unaff_s2 + 500) * 0x19 + -0x15e;
      sStack00000014 = *(short *)(unaff_s2 + 500) * 0xf + -200;
      FUN_80037780(5000,(int)((*(ushort *)(unaff_s2 + 0x66) + 0x800) * 0x10000) >> 0x10,iVar4,
                   &uStack00000010);
      *(short *)(unaff_s2 + 500) = *(short *)(unaff_s2 + 500) + 1;
    }
    if (*(byte *)(unaff_s2 + 0x1e9) < 0x2a) {
      if ((DAT_800e9012 & 8) != 0) {
        if (*(char *)(unaff_s2 + 0x206) < '\x04') {
          iVar4 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x120);
          *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + -0x50;
          FUN_80066288();
          iVar4 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x18a0);
          sVar1 = *(short *)(iVar4 + 0x10) + -0x50;
        }
        else {
          iVar4 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x120);
          *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + 200;
          FUN_80066288();
          iVar4 = *(int *)(*(int *)(unaff_s2 + 0x234) + 0x18a0);
          sVar1 = *(short *)(iVar4 + 0x10) + 200;
        }
        *(short *)(iVar4 + 0x10) = sVar1;
        FUN_80066288();
      }
      cVar2 = *(char *)(unaff_s2 + 0x206) + -1;
      *(char *)(unaff_s2 + 0x206) = cVar2;
      if (cVar2 == -1) {
        *(undefined1 *)(unaff_s2 + 0x206) = 5;
      }
    }
  }
  cVar2 = *(char *)(unaff_s2 + 0x1e9);
  if (cVar2 == '(') {
    if ((DAT_800e9012 & 0xc) != 0) {
      FUN_8008794c();
    }
    cVar2 = *(char *)(unaff_s2 + 0x1e9);
  }
  if ((cVar2 == '2') && ((DAT_800e9012 & 0xc) != 0)) {
    FUN_8008794c();
    FUN_8008794c();
    FUN_8008794c();
    FUN_8008794c();
    FUN_8008794c();
  }
  if (((0x32 < *(byte *)(unaff_s2 + 0x1e9)) && (*(char *)(unaff_s2 + 0x207) == '\0')) &&
     ((DAT_800e9012 & 8) != 0)) {
    iVar3 = *(int *)(unaff_s2 + 0x234);
    iVar4 = *(int *)(iVar3 + 0x120);
    *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + 200;
    iVar4 = *(int *)(iVar3 + 0x120);
    if (0x1000 < *(short *)(iVar4 + 0x10)) {
      *(undefined2 *)(iVar4 + 0x10) = 0x1000;
      *(undefined1 *)(unaff_s2 + 0x207) = 1;
    }
    FUN_80066288();
    iVar4 = *(int *)(unaff_s2 + 0x234);
    iVar3 = *(int *)(iVar4 + 0x18a0);
    *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + 200;
    iVar4 = *(int *)(iVar4 + 0x18a0);
    if (0x1000 < *(short *)(iVar4 + 0x10)) {
      *(undefined2 *)(iVar4 + 0x10) = 0x1000;
    }
    FUN_80066288();
  }
  if ((*(byte *)(unaff_s2 + 0x1e9) - 0x24 < 0x13) && ((*(byte *)(unaff_s2 + 0x1e9) & 3) == 0)) {
    FUN_80037780(0x21770,(int)*(short *)(unaff_s2 + 0x66),*(int *)(unaff_s2 + 0x234) + 0x38,0);
  }
  if (*(char *)(unaff_s2 + 0x1e9) == 'F') {
    *(undefined1 *)(DAT_800e13f4 + 6) = 5;
  }
  cVar2 = FUN_80089d54();
  *(char *)(unaff_s2 + 6) = *(char *)(unaff_s2 + 6) + cVar2;
  caseD_4();
  return;
}
