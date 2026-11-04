/* FUN_80088764
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088764  body 0x80088764..0x800888eb  size 392 B
 * body sha256 1117657d6cef696edf94a80aa2ea84a8b634b1f1eb55d8c0696c4a959410e190
 * provider record sha256 91ea478c41f3cad01ce982c7ffa126a3c90f4dd24f0536ac1ca13cb75d3cd043
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80088850) */

void FUN_80088764(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_40 [24];
  
  uVar1 = func_0x800072e0();
  DAT_8012baf8 = DAT_8012baf8 + 1;
  if (DAT_8012bafc < DAT_8012baf8) {
    DAT_8012bafc = DAT_8012baf8;
  }
  func_0x80007300(uVar1);
  func_0x8000efa0(param_1,param_3);
  iVar3 = 0;
  do {
    uVar2 = param_3 - iVar3;
    if (0x1000 < (uint)(param_3 - iVar3)) {
      uVar2 = 0x1000;
    }
    func_0x8000bd80(auStack_40,0,0,param_2 + iVar3,param_1 + iVar3,uVar2,&DAT_8012bd30);
    osRecvMesg(&DAT_8012bcf8,0,1);
    iVar3 = iVar3 + uVar2;
  } while (iVar3 != param_3);
  func_0x80007320(param_1,param_3);
  func_0x80011390();
  uVar1 = func_0x800072e0();
  DAT_8012baf8 = DAT_8012baf8 + -1;
  func_0x80007300(uVar1);
  return;
}
