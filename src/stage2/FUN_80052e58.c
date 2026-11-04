/* FUN_80052e58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052e58  body 0x80052e58..0x80052eeb  size 148 B
 * body sha256 c12667b3914895355265ce060c589ab801c7ba224d70246d609920d69ab1bd7e
 * provider record sha256 b598919fb8bca99ab09c39abce7834f7d539fe15a533daca9b6d1dad66fa75fe
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
byte FUN_80052e58(char *param_1)

{
  short sVar1;
  ushort uVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  
  bVar5 = 0;
  uVar4 = 0;
  pbVar3 = (byte *)(param_1 + 1);
  do {
    if (*param_1 != '\0') {
      if (*(short *)(pbVar3 + 1) == 0) {
        sVar1 = *(short *)(pbVar3 + 3);
        *(short *)(pbVar3 + 3) = sVar1 + -1;
        if ((short)(sVar1 + -1) == 0) {
          *param_1 = '\0';
        }
        if (*(short *)(pbVar3 + 5) != 0) {
          uVar2 = *(ushort *)(pbVar3 + 7);
          *(short *)(pbVar3 + 7) = (short)((uint)uVar2 + (uint)*(ushort *)(pbVar3 + 5));
          *pbVar3 = (byte)((uint)uVar2 + (uint)*(ushort *)(pbVar3 + 5) >> 7);
        }
        if (bVar5 < *pbVar3) {
          bVar5 = *pbVar3;
        }
      }
      else {
        *(short *)(pbVar3 + 1) = *(short *)(pbVar3 + 1) + -1;
      }
    }
    uVar4 = uVar4 + 1;
    pbVar3 = pbVar3 + 10;
    param_1 = param_1 + 10;
  } while (uVar4 < 0x20);
  return bVar5;
}
