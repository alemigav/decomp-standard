/* FUN_8017f85c
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017f85c  body 0x8017f85c..0x8017facb  size 624 B
 * body sha256 5d64d3d6442be4027c20eb2f53818450aa69dc55dc928bc39648835791b6df59
 * provider record sha256 c6d21c520eac43a1082540e85bbd13fbdba0da256800d33c31b7741e79e561bc
 * callees 9 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_8017f85c(int param_1,uint param_2,int param_3,undefined2 param_4,undefined4 param_5,
            undefined4 param_6,uint param_7)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_42 [26];
  
  func_0x80082200(auStack_42,0,0x1a);
  *(char *)(param_1 + 3) = (char)(param_7 >> 0xd) + ((param_7 & 0x1fff) != 0);
  func_0x800823b0(param_1 + 4,param_6);
  DAT_80180d3c = param_2 & 0xff;
  DAT_80180adc = 7;
  DAT_80180ae0 = &DAT_80180d3c;
  DAT_80180d40 = &DAT_80180ad8;
  DAT_80180d50 = param_7;
  DAT_80180d54 = param_5;
  DAT_80180d58 = CONCAT22(param_4,DAT_80180d58._2_2_);
  func_0x80082224(0x80180d5e,param_3,0x10);
  func_0x80082224(0x80180d5a,param_3 + 0x10,4);
  uVar2 = DAT_80180d58;
  uVar3 = DAT_80180d54;
  DAT_80180d48 = 1;
  DAT_80180d44 = 0;
  DAT_80180d74 = &DAT_80181f94;
  DAT_80180d70 = param_1;
  if (DAT_80180d78 == '\0') {
    iVar4 = (*(byte *)(param_3 + 0x12) - 0x1a) * 10 + -0x1a + (uint)*(byte *)(param_3 + 0x13);
    (&DAT_80181fcc)[iVar4 * 0x209] = DAT_80180d50;
    (&DAT_80181fd0)[iVar4 * 0x209] = uVar3;
    (&DAT_80181fd4)[iVar4 * 0x209] = uVar2;
    (&DAT_80181fd8)[iVar4 * 0x209] = 0;
    (&DAT_80181fdc)[iVar4 * 0x209] = 0;
    (&DAT_80181fe0)[iVar4 * 0x209] = 0;
    (&DAT_80181fe4)[iVar4 * 0x209] = 0;
    (&DAT_80181fe8)[iVar4 * 0x209] = 0;
    func_0x8000de9c(&UNK_80181fec + iVar4 * 0x824,DAT_80180d70,DAT_80180d50);
    uVar3 = func_0x8009c28c(&DAT_80181fcc + iVar4 * 0x209,0x820);
    bVar1 = _DAT_800c52d0 == 0;
    (&DAT_80181fc8)[iVar4 * 0x209] = uVar3;
    if ((bVar1) || (iVar4 = func_0x8009c0c4(), iVar4 == 0)) {
      DAT_80180ad8 = 0;
    }
    else {
      DAT_80180ad8 = 0xb;
    }
    osSendMesg(DAT_80180d74,0,0);
  }
  else {
    func_0x800879a0(&DAT_80180adc);
    osRecvMesg(&DAT_80181f94,0,1);
  }
  return DAT_80180ad8;
}
