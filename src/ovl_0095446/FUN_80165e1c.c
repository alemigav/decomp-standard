/* FUN_80165e1c
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80165e1c  body 0x80165e1c..0x8016621f  size 1028 B
 * body sha256 8f8bd952a02e94c683b0cecdd73b540d81a68b47641bb08659a1fe2fdfd216f7
 * provider record sha256 56dca2e78bae31b1673c1377d7484d5e7e11ad68a6876b04d33ecddb32905779
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165e1c(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar5;
  ushort uVar3;
  short sVar4;
  uint uVar1;
  int iVar2;
  byte bVar6;
  short local_20;
  short local_1e;
  short local_1c;
  
  *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) | 0x52;
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x2001f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 1;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) | 0x40;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 0x200;
  case 1:
    if (*(char *)(param_1 + 0x1e9) == '#') {
      func_0x80052c6c(8,0x96,0);
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_1 + 0x234);
      *(undefined1 *)(param_1 + 6) = 2;
      *(uint *)(iVar2 + 0xeb0) = *(uint *)(iVar2 + 0xeb0) | 0x200;
      *(uint *)(iVar2 + 0x11a0) = *(uint *)(iVar2 + 0x11a0) | 0x200;
      *(uint *)(iVar2 + 0x1028) = *(uint *)(iVar2 + 0x1028) | 0x200;
      *(undefined4 *)(param_1 + 0x1e8) = 0x9001f00;
      *(undefined2 *)(param_1 + 500) = 0xb4;
      *(undefined1 *)(param_1 + 0x207) = 0;
    }
    func_0x80032b5c(param_1,0);
    iVar2 = *(int *)(param_1 + 0x234);
    func_0x8004226c(iVar2 + 0x1b0,iVar2 + 0xd40,iVar2 + 0xd70);
    break;
  case 2:
    cVar5 = *(char *)(param_1 + 0x207) + -1;
    *(char *)(param_1 + 0x207) = cVar5;
    if (cVar5 == -1) {
      bVar6 = func_0x80033604(param_1);
      *(byte *)(param_1 + 0x207) = (bVar6 & 1) + 1;
      uVar3 = func_0x80033604();
      *(ushort *)(param_1 + 0x1f6) = 0x20 - (uVar3 & 0x3f);
      uVar3 = func_0x80033604();
      *(ushort *)(param_1 + 0x1e0) = 0x10 - (uVar3 & 0x1f);
      uVar3 = func_0x80033604();
      *(ushort *)(param_1 + 0x1e4) = 0x10 - (uVar3 & 0x1f);
    }
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x1f6);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
    func_0x80089d54(param_1,param_2,param_3,0x80);
    sVar4 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar4;
    if (sVar4 == -1) {
      *(undefined1 *)(param_1 + 6) = 3;
      *(undefined2 *)(*(int *)(param_1 + 0x234) + 0xe54) = 0xff;
    }
    if ((*(ushort *)(param_1 + 500) & 3) == 0) {
      iVar2 = *(int *)(param_1 + 0x234);
      uVar3 = func_0x80033604();
      local_20 = *(short *)(iVar2 + 0xd56) - ((uVar3 & 0x7f) - 0x40);
      uVar3 = func_0x80033604();
      local_1e = *(short *)(iVar2 + 0xd5a) - ((uVar3 & 0x7f) - 0x40);
      uVar3 = func_0x80033604();
      local_1c = *(short *)(iVar2 + 0xd5e) - ((uVar3 & 0x7f) - 0x40);
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) << 3 | 0x91000,
                      (int)((*(ushort *)(param_1 + 0x66) - 0x400) * 0x10000) >> 0x10,iVar2 + 0x1b0,
                      &local_20);
    }
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x1e8) = 0xb001f00;
    *(undefined1 *)(param_1 + 6) = 4;
  case 4:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 6) = 5;
      *(undefined4 *)(param_1 + 0x1e8) = 0x3001f00;
    }
    break;
  case 5:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      *(undefined1 *)(param_1 + 700) = 6;
      *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) & 0x7f;
      *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) & 0xfdff;
    }
  }
  if ((*(byte *)(param_1 + 0x1e9) & 0xf) == 0) {
    bVar6 = func_0x80033604();
    DAT_80167fca = '\x03' - bVar6 % 6;
    bVar6 = func_0x80033604();
    DAT_80167fcb = '\x0f' - bVar6 % 0x1e;
  }
  return;
}
