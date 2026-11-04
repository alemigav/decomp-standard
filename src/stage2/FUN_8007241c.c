/* FUN_8007241c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007241c  body 0x8007241c..0x800724fb  size 224 B
 * body sha256 18157060165b0d0c4ff0840602696ba833265007ee08f7c4c8a31196683ad809
 * provider record sha256 ea3b12b25a832d3ec714001689ba804b310114e64402373ae80aae0fb60630ef
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8007241c(int param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  iVar4 = *(int *)(param_1 + 0x1c);
  bVar1 = *(byte *)(iVar4 + 1);
  sVar2 = *(short *)(iVar4 + 4);
  local_1c = 0x140;
  local_20 = 0;
  local_1e = 0;
  local_1a = 0xf0;
  iVar3 = (int)sVar2;
  FUN_800274f8(CONCAT11(*(undefined1 *)(iVar4 + 2),bVar1),iVar3,*(undefined1 *)(iVar4 + 3),7);
  FUN_800275c0((uint)bVar1,0,0,&local_20);
  if (iVar3 != 0) {
    if (iVar3 < 1) {
      (&DAT_800e9184)[(uint)bVar1 * 0x16] = sVar2 + -0x8000;
    }
    else {
      (&DAT_800e9184)[(uint)bVar1 * 0x16] = 0;
    }
  }
  *(int *)(param_1 + 0x1c) = iVar4 + 6;
  return 1;
}
