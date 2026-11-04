/* FUN_8016375c
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x8016375c  body 0x8016375c..0x80163897  size 316 B
 * body sha256 adcd9359f9f04e0bf425761c6d02cea422dd707eb86b03fbd12dc6afaa951df2
 * provider record sha256 66a83f270a0441c76cca1a12fc9bb32e019c0ead058af77842de6a6f0ed644ed
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016375c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  short local_48;
  short local_46;
  short local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined1 auStack_38 [32];
  
  iVar2 = *(int *)(param_1 + 0x250);
  iVar1 = FUN_80163724(iVar2,&local_48,*(byte *)(param_1 + 0x1ab) - 1);
  *(int *)(param_1 + 0x28) = (int)local_48;
  *(int *)(param_1 + 0x2c) = (int)local_46;
  *(int *)(param_1 + 0x30) = (int)local_44;
  local_48 = *(short *)(iVar2 + 100) + *(short *)(iVar1 + 0x58);
  local_46 = *(short *)(iVar2 + 0x66) + *(short *)(iVar1 + 0x5a);
  local_44 = *(short *)(iVar2 + 0x68) + *(short *)(iVar1 + 0x5c);
  func_0x80040e58(&local_48,auStack_38);
  local_40 = *(undefined2 *)(param_1 + 0x2b6);
  local_3e = *(undefined2 *)(param_1 + 0x2b8);
  local_3c = *(undefined2 *)(param_1 + 0x2ba);
  func_0x8004276c(auStack_38,&local_40,&local_48);
  *(undefined2 *)(param_1 + 100) = *(undefined2 *)(iVar2 + 100);
  *(short *)(param_1 + 0x66) = *(short *)(iVar2 + 0x66) + *(short *)(param_1 + 700);
  *(short *)(param_1 + 0x68) = *(short *)(iVar2 + 0x68) + *(short *)(param_1 + 0x2c2);
  if (param_2 != 0) {
    *(short *)(param_1 + 100) = *(short *)(param_1 + 100) + *(short *)(iVar1 + 0x58);
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(iVar1 + 0x5a);
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + *(short *)(iVar1 + 0x5c);
  }
  return;
}
