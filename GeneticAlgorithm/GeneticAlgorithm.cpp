// GeneticAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/**
 *
 * @author SolutE
 */

class Evolution implements java.io.Serializable{
    private ArrayList<Generation> thisEvo;
    private Generation currGen;
    private SolvedDB db;
    private Yaml configFileName;
    private String evoFileName;        
    public Evolution(String evoFileName_, SolvedDB db, String configFileName_) throws ClassNotFoundException{
        loadEvo(evoFileName_);
        this.db = db;
        this.evoFileName = evoFileName_;
        this.configFileName = configFileName_;
    
    }
    public void loadEvo(String evoFileName_) throws ClassNotFoundException{
        //load evolution from evofile
        ArrayList<Generation> e = null;
        try {
            try (FileInputStream fileIn = new FileInputStream(evoFileName_); ObjectInputStream in = new ObjectInputStream(fileIn)) {
                e = (ArrayList<Generation>) in.readObject();
            }
        }catch(IOException i){
        }
        setCurrGen(getThisEvo().get(getThisEvo().size() - 1));
        this.setEvoFileName(evoFileName_);
    }
    public void saveEvo(String evoFileName_) throws ClassNotFoundException{
        //save thisEvo to evofile
    try
    {
          try (FileOutputStream fileOut = new FileOutputStream(evoFileName_); ObjectOutputStream out = new ObjectOutputStream(fileOut)) {
              out.writeObject(getThisEvo());
          }
    }catch(IOException i){} 
    }
    
    public Generation createNewGen(){
        return null;        
    }

    /**
     * @return the currGen
     */
    public Generation getCurrGen() {
        return currGen;
    }

    /**
     * @param currGen the currGen to set
     */
    public void setCurrGen(Generation currGen) {
        this.currGen = currGen;
    }

    /**
     * @return the db
     */
    public SolvedDB getDb() {
        return db;
    }

    /**
     * @param db the db to set
     */
    public void setDb(SolvedDB db) {
        this.db = db;
    }

    /**
     * @return the thisEvo
     */
    public ArrayList<Generation> getThisEvo() {
        return thisEvo;
    }

    /**
     * @param thisEvo the thisEvo to set
     */
    public void setThisEvo(ArrayList<Generation> thisEvo) {
        this.thisEvo = thisEvo;
    }

    /**
     * @return the configFileName
     */
    public String getConfigFileName() {
        return configFileName;
    }

    /**
     * @param configFileName the configFileName to set
     */
    public void setConfigFileName(String configFileName) {
        this.configFileName = configFileName;
    }

    /**
     * @return the evoFileName
     */
    public String getEvoFileName() {
        return evoFileName;
    }

    /**
     * @param evoFileName the evoFileName to set
     */
    public void setEvoFileName(String evoFileName) {
        this.evoFileName = evoFileName;
    }

}
class Generation implements java.io.Serializable{
    private ArrayList<Chromosome> thisGen;
    private File configFile;
    private Integer size;
    private SolvedDB db;

    public Generation(File configFile, Integer size, SolvedDB db) {
        //create new gen based on config and size
    }
    // create absolutely specified generation
    public Generation(ArrayList<Chromosome> thisGen, File configFile, SolvedDB db) {
        this.thisGen = thisGen;
        this.configFile = configFile;
        this.db = db;
    }
    //create new generation from an old one
    public Generation(ArrayList<Chromosome> oldGen, File configFile, Integer size, SolvedDB db) {
        this.thisGen = oldGen;
        this.configFile = configFile;
        this.size = size;
        this.db = db;
    }   
    private void performModifications(){
        
    }
    private ArrayList<Chromosome> chooseParents(){
        return null;
        
    }
    private void performCrossover(ArrayList<Chromosome> parents){
        
    }
    private void mutateGen(){
        
    }

    /**
     * @return the thisGen
     */
    public ArrayList<Chromosome> getThisGen() {
        return thisGen;
    }

    /**
     * @param thisGen the thisGen to set
     */
    public void setThisGen(ArrayList<Chromosome> thisGen) {
        this.thisGen = thisGen;
    }

    /**
     * @return the configFile
     */
    public File getConfigFile() {
        return configFile;
    }

    /**
     * @param configFile the configFile to set
     */
    public void setConfigFile(File configFile) {
        this.configFile = configFile;
    }

    /**
     * @return the size
     */
    public Integer getSize() {
        return size;
    }

    /**
     * @param size the size to set
     */
    public void setSize(Integer size) {
        this.size = size;
    }

    /**
     * @return the db
     */
    public SolvedDB getDb() {
        return db;
    }

    /**
     * @param db the db to set
     */
    public void setDb(SolvedDB db) {
        this.db = db;

    }
    
    
}
    
    
class Chromosome implements java.io.Serializable{
    private ArrayList<Boolean> thisChromosome;
    private File configFile;
    private Integer length;

    public Chromosome(File configFile, Integer length) {
        this.length = length;
    }
    
    
    public Chromosome(ArrayList<Boolean> thisChromosome, File configFile, Integer length) {
        this.thisChromosome = thisChromosome;
        this.configFile = configFile;
        this.length = length;
    }
    public Integer startSimulation(){
        return 0;           
    }

    public void mutateChromosome(){

    }

    /**
     * @return the thisChromosome
     */
    public ArrayList<Boolean> getThisChromosome() {
        return thisChromosome;
    }

    /**
     * @param thisChromosome the thisChromosome to set
     */
    public void setThisChromosome(ArrayList<Boolean> thisChromosome) {
        this.thisChromosome = thisChromosome;
    }

    /**
     * @return the configFile
     */
    public File getConfigFile() {
        return configFile;
    }

    /**
     * @param configFile the configFile to set
     */
    public void setConfigFile(File configFile) {
        this.configFile = configFile;
    }

    /**
     * @return the length
     */
    public Integer getLength() {
        return length;
    }

    /**
     * @param length the length to set
     */
    public void setLength(Integer length) {
        this.length = length;
    }
        
}
    
    
class SolvedDB {
    
}

public class GeneticAlgorithm {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Yaml yaml = new Yaml();
String document = "  a: 1\n  b:\n    c: 3\n    d: 4\n";
System.out.println(document);
System.out.println(yaml.dumpAsMap(yaml.load(document)));
        // TODO code application logic here
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

