/* FUN_80097fd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80097fd0  body 0x80097fd0..0x80098087  size 184 B
 * body sha256 7d4ea5e1b0cad2f8e4c0d1bae7f24064174c9b426a64369225752a43b556b069
 * provider record sha256 2543e26f17410a3d87b4588fdbac7035521f8651afb5d3d713e9f28cf060e5e5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80097fd0(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  
  iVar6 = 5;
  iVar3 = DAT_800c52dc + 0x3bd48;
  sVar5 = 0xc0;
  do {
    iVar6 = iVar6 + -1;
    iVar2 = 7;
    sVar1 = 0x150;
    iVar4 = iVar3;
    do {
      sVar1 = sVar1 + -0x30;
      iVar2 = iVar2 + -1;
      FUN_800478b8(iVar4,sVar1,sVar5);
      iVar3 = iVar4 + 0x14;
      DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar4,0,0);
      iVar4 = iVar3;
    } while (iVar2 != 0);
    sVar5 = sVar5 + -0x30;
  } while (iVar6 != 0);
  return;
}
