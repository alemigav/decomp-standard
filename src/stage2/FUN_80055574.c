/* FUN_80055574
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80055574  body 0x80055574..0x800558fb  size 904 B
 * body sha256 0953feaeae528a86df9077819ca5fa490b73ff13fed3a51707cf9c46c982bb14
 * provider record sha256 122f3ac991100ed0c1d1dd2daec0e0e5d62dacc2e3c643906858173f7c0fc736
 * callees 16 direct (16 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80055574(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int unaff_s4;
  
  iVar2 = DAT_800c52dc;
  FUN_80085398(DAT_800c52dc + 0x17800,DAT_800c52dc + 0x3b800,&DAT_800b8f60);
  uVar5 = iVar2 + 0x17807U & 0xfffffff8;
  FUN_8008af50(2);
  *(uint *)(param_1 + 0x218) = uVar5;
  iVar2 = func_0x80005e84(*(undefined2 *)(&DAT_8010db80 + (uint)*(byte *)(param_1 + 8) * 2),uVar5);
  uVar5 = iVar2 + 7U & 0xfffffff8;
  *(uint *)(param_1 + 0x1a4) = uVar5;
  iVar2 = func_0x80005ee8(*(undefined2 *)(&DAT_8010dba0 + (uint)*(byte *)(param_1 + 8) * 2),uVar5);
  uVar5 = iVar2 + 7U & 0xfffffff8;
  *(undefined4 *)(param_1 + 0x220) = 0;
  *(undefined4 *)(param_1 + 0x21c) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(uint *)(param_1 + 0xc4) = uVar5;
  iVar2 = func_0x80004cfc(*(undefined2 *)(&DAT_8010dbc0 + (uint)*(byte *)(param_1 + 8) * 2),uVar5,1,
                          &DAT_800b8f64);
  FUN_800824b8(*(undefined4 *)(param_1 + 0xc4));
  uVar1 = *(undefined2 *)(&DAT_8010dbe0 + (uint)*(byte *)(param_1 + 8) * 2);
  FUN_80087868(param_1 + 0x78,uVar1);
  iVar3 = FUN_800874d4(uVar5 + iVar2 + 7 & 0xfffffff8,param_1 + 0xb8,param_1 + 0xbc,uVar1,
                       param_1 + 0x78);
  *(undefined4 *)(param_1 + 0xdc) = 0xffffffff;
  iVar2 = iVar3;
  if (*(char *)(param_1 + 8) == '\x0e') {
    iVar2 = iVar3 + 0x2800;
    unaff_s4 = iVar3;
  }
  DAT_800df924 = FUN_80088eec(param_1,iVar2);
  uVar4 = FUN_80088f1c(param_1,DAT_800df924,*(undefined4 *)(param_1 + 0x1a4),1);
  if (*(char *)(param_1 + 8) == '\x0e') {
    FUN_80035c08(param_1,unaff_s4);
  }
  DAT_800df920 = 0xd2706ca4;
  iVar2 = *(int *)(param_1 + 0x234);
  DAT_8010dd58 = *(undefined4 *)(iVar2 + 0x10dc);
  DAT_8010dd5c = *(undefined4 *)(iVar2 + 0x10e4);
  DAT_8010dd60 = *(undefined4 *)(iVar2 + 0x10e0);
  DAT_8010dd64 = *(undefined4 *)(iVar2 + 0x10e8);
  DAT_800df928 = uVar4;
  *(undefined2 *)(param_1 + 0x1fe) = 200;
  if (*(char *)(param_1 + 8) == '\r') {
    *(undefined2 *)(param_1 + 0x1fe) = 400;
  }
  *(undefined2 *)(param_1 + 0x27a) = 0x1000;
  *(undefined2 *)(param_1 + 0x1f0) = 0;
  if (DAT_8012bfa0 == -0x80) {
    *(undefined2 *)(param_1 + 0x1aa) = 0;
  }
  else {
    *(ushort *)(param_1 + 0x1aa) = (ushort)DAT_8012bfa2;
  }
  FUN_8005a3d0(param_1);
  *(undefined1 *)(param_1 + 9) = 0x80;
  DAT_800e12d8 = 0;
  DAT_800e8cb8 = (ushort)*(byte *)(param_1 + 8);
  FUN_800761ac(*(undefined1 *)(param_1 + 0x1ab));
  *(undefined4 *)(param_1 + 0x284) = 1;
  *(undefined2 *)(param_1 + 0x134) = 0xfa06;
  *(undefined2 *)(param_1 + 0x13a) = 0x5fa;
  *(code **)(param_1 + 0x2a0) = FUN_800558fc;
  *(undefined2 *)(param_1 + 0x136) = 0x1c2;
  *(undefined2 *)(param_1 + 0x138) = 0x1c2;
  *(undefined2 *)(param_1 + 300) = 0x1c2;
  *(undefined2 *)(param_1 + 0x12e) = 0x1c2;
  *(undefined1 **)(param_1 + 0x2a4) = &LAB_800559a8;
  *(undefined2 *)(param_1 + 0x130) = 0;
  *(undefined2 *)(param_1 + 0x132) = 0;
  if (*(char *)(param_1 + 8) == '\x0e') {
    **(uint **)(param_1 + 0x234) = **(uint **)(param_1 + 0x234) | 0x4000;
  }
  DAT_8010dc01 = 0;
  if (((*(char *)(param_1 + 8) == '\0') || (*(char *)(param_1 + 8) == '\x02')) &&
     (iVar2 = FUN_800837ac(&DAT_800e8ce0,0x3e), iVar2 != 0)) {
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
  }
  iVar2 = FUN_8008cce4(*(ushort *)(param_1 + 0x1aa) & 0xfff);
  if (iVar2 != 0) {
    *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) | 1;
  }
  return;
}
